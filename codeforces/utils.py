import requests
import json

def fetch_api_data(tag):
    url = f'https://codeforces.com/api/problemset.problems?tags={tag}'

    try:
        response = requests.get(url)
        response.raise_for_status()
        data_dict = response.json()
        return data_dict

    except requests.exceptions.HTTPError as http_err:
        print(f"HTTP error occurred: {http_err}")
    except requests.exceptions.ConnectionError as conn_err:
        print(f"Connection error occurred: {conn_err}")
    except requests.exceptions.Timeout as timeout_err:
        print(f"Timeout error occurred: {timeout_err}")
    except requests.exceptions.RequestException as req_err:
        print(f"An unexpected error occurred: {req_err}")
    except json.JSONDecodeError:
        print("Failed to decode JSON from the response.")

    return None


def filtered_problem(tag='geometry', rating_start=0, rating_end=4000):
    data = fetch_api_data(tag)
    if not data:
        return []

    problems = data['result']['problems']
    filtered = []
    for problem in problems:
        if 'rating' in problem and rating_start <= problem['rating'] <= rating_end:
            # Use a unique identifier (contestId + index)
            filtered.append((problem['contestId'], problem['index']))
    return filtered


def get_user_solved_set(username):
    url = f"https://codeforces.com/api/user.status?handle={username}&from=1&count=100000"
    try:
        response = requests.get(url)
        response.raise_for_status()
        data = response.json()

        solved = set()
        for sub in data['result']:
            if sub.get('verdict') == 'OK':
                problem = sub['problem']
                solved.add((problem['contestId'], problem['index']))
        return solved
    except Exception as e:
        print(f"Error fetching user submissions: {e}")
        return set()


def progress(username, tag='geometry', rating_start=0, rating_end=4000):
    tagged_problems = filtered_problem(tag, rating_start, rating_end)
    solved = get_user_solved_set(username)

    solved_tagged = [p for p in tagged_problems if p in solved]

    print(f"User '{username}' has solved {len(solved_tagged)} out of {len(tagged_problems)} '{tag}' problems ")



'''
from utils import filtered_problem, progress
problems = filtered_problem('geometry',1500,2000)

from utils import progress
progress(username='Luca0506', tag='geometry', rating_start=1500, rating_end=2000)

'''