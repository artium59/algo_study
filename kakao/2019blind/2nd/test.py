import requests


url = 'http://localhost:8000'


def start(user, problem, count):
    uri = url + '/start' + '/' + user + '/' + str(problem) + '/' + str(count)
    return requests.post(uri).json()


def oncalls(token):
    uri = url + '/oncalls'
    request = requests.get(uri, headers={'X-Auth-Token': token})
    request = request.json()
    print('--------------------')
    for k, v in request.items():
        print(f'{k}: {v}')
    print('--------------------')
    return request


def action(token, cmds):
    uri = url + '/action'
    return requests.post(uri, headers={'X-Auth-Token': token}, json={'commands': cmds}).json()


def command(elevator, calls, direction, expect, check, top_floor):
    cnt = 0
    ret = {"elevator_id": elevator['id'], "command": "X", "call_ids": []}

    if elevator['status'] == 'STOPPED':
        # 내릴 사람이 있다면 무조건 내린다.
        for passenger in elevator['passengers']:
            if passenger['end'] == elevator['floor']:
                ret['command'] = 'OPEN'
                return ret

        # 현재 층과 관련된 승객이 있는지 확인
        for call in calls:
            # 탈 사람이 있고, 방향이 같고, 자리가 있으면 태운다.
            if call['start'] == elevator['floor']\
                and len(elevator['passengers']) < 8\
                    and direction[elevator['id']] * (call['end'] - call['start']) >= 0:
                ret['command'] = 'OPEN'
                return ret

        # 1층이라면 올라간다.
        if elevator['floor'] == 1:
            ret['command'] = 'UP'
            direction[elevator['id']] = 1
        # 꼭대기라면 내려간다.
        elif elevator['floor'] == top_floor:
            ret['command'] = 'DOWN'
            direction[elevator['id']] = -1
        # 아니라면 방향 유지
        else:
            ret['command'] = 'UP' if direction[elevator['id']] == 1 else 'DOWN'

    elif elevator['status'] == 'OPENED':
        # 내릴 사람이 있다면 무조건 내린다.
        for passenger in elevator['passengers']:
            if passenger['end'] == elevator['floor']:
                ret['command'] = 'EXIT'
                ret['call_ids'].append(passenger['id'])

        if ret['command'] != 'X':
            return ret

        # 타려는 승객이 있다면
        for call in calls:
            # 층과 방향이 같은지 체크한다.
            if call['start'] == elevator['floor'] and direction[elevator['id']] * (call['end'] - call['start']) >= 0:
                # 자리가 있는지, 앞에 먼저 탔는지 체크한다.
                if len(elevator['passengers']) < 8 and check[call['id']]:
                    # 자리가 있다면 일단 태우자.
                    check[call['id']] = False
                    ret['command'] = 'ENTER'
                    ret['call_ids'].append(call['id'])

        if ret['command'] != 'X':
            return ret

        ret['command'] = 'CLOSE'

    elif elevator['status'] == 'UPWARD':
        # 꼭대기면 stop
        if elevator['floor'] == top_floor:
            ret['command'] = 'STOP'
            direction[elevator['id']] = 0
        # 아니면
        else:
            # 내릴 사람이 있다면 무조건 내린다.
            for passenger in elevator['passengers']:
                if passenger['end'] == elevator['floor']:
                    ret['command'] = 'STOP'
                    return ret

            # 탈 승객이 있다면
            for call in calls:
                # 층과 방향이 같은지 체크한다.
                if call['start'] == elevator['floor'] and direction[elevator['id']] * (call['end'] - call['start']) >= 0:
                    # 탈 공간이 남아있어야 한다.
                    if len(elevator['passengers'])+cnt < 8 and expect[call['id']]:
                        expect[call['id']] = False
                        cnt += 1

                        ret['command'] = 'STOP'

            if ret['command'] != 'X':
                return ret

            ret['command'] = 'UP'

    elif elevator['status'] == 'DOWNWARD':
        # 1층이면 stop
        if elevator['floor'] == 1:
            ret['command'] = 'STOP'
            direction[elevator['id']] = 0
        # 아니면
        else:
            # 내릴 사람이 있다면 무조건 내린다.
            for passenger in elevator['passengers']:
                if passenger['end'] == elevator['floor']:
                    ret['command'] = 'STOP'
                    return ret

            # 탈 승객이 있다면
            for call in calls:
                # 층과 방향이 같은지 체크한다.
                if call['start'] == elevator['floor'] and direction[elevator['id']] * (call['end'] - call['start']) >= 0:
                    # 탈 공간이 남아있어야 한다.
                    if len(elevator['passengers']) + cnt < 8 and expect[call['id']]:
                        expect[call['id']] = False
                        cnt += 1

                        ret['command'] = 'STOP'

            if ret['command'] != 'X':
                return ret

            ret['command'] = 'DOWN'
    else:
        print('ERROR!!')

    return ret


def simulator(problem):
    user = 'tester'
    count = 4

    top_floor = 5 if problem == 0 else 25

    # 1: upward, -1: downward, 0: 1층 or top_floor
    direction = [1] * count
    expect = [True] * 500
    check = [True] * 500

    ret = start(user, problem, count)
    token = ret['token']
    print('Token for %s is %s' % (user, token))

    while True:
        cur = oncalls(token)
        cmds = []

        if cur['is_end']:
            break

        for elevator in cur['elevators']:
            cmds.append(command(elevator, cur['calls'], direction, expect, check, top_floor))

        action(token, cmds)
        print(cmds)


if __name__ == '__main__':
    simulator(1)
