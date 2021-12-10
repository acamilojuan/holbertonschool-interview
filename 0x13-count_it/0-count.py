#!/usr/bin/python3
""" Recursive fx that queries the Reddit API """
from requests import request


def generate_count(word_list):
    """ Method that generate count Fx """
    count = {k: 0 for k in word_list}
    add = {}
    for k in word_list:
        if k not in add:
            add[k] = 0
        add[k] += 1
    return (count, add)


def count_words(subreddit, word_list, after="", count={}, add={}, init=0):
    """ Fx to count """
    if not init:
        count, add = generate_count(word_list)

    url = "https://api.reddit.com/r/{}/hot?after={}".format(subreddit, after)
    headers = {"User-Agent": "Python3"}
    response = request("GET", url, headers=headers).json()
    try:
        data = response.get('data')
        data_after = data.get('after')
        top = data.get('children')

        for item in top:
            data = item.get('data')['title']
            for word in count:
                amount = data.lower().split(' ').count(word.lower())
                count[word] += amount

        if data_after:
            count_words(subreddit, word_list, data_after, count, add, 1)
        else:
            item_output = sorted(count.items(), key=lambda tup: tup[::-1])
            desc = sorted(item_output, key=lambda tup: tup[1], reverse=True)

            for name, cnt in desc:
                cnt *= add[name]
                if cnt:
                    print('{}: {}'.format(name.lower(), cnt))
    except Exception:
        return None
