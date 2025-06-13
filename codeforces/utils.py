from bs4 import BeautifulSoup
import requests
import json

def readTrFromFile():
    # The name of the file you saved in Step 1.
    # Make sure this file is in the same directory as your Python script.
    file_path = 'mypage.html'

    print(f"Attempting to read from file: {file_path}")

    try:
        # Use 'with open' to safely open and read the file.
        # 'r' is for read mode, and 'utf-8' encoding is best for web content.
        with open(file_path, 'r', encoding='utf-8') as file:
            soup = BeautifulSoup(file, 'html.parser')

            all_tr_elements = soup.find_all('tr')
            accepted_problem_elements = soup.find_all('tr', class_='accepted-problem')

            # Get the counts
            total_tr_count = len(all_tr_elements)
            accepted_problem_count = len(accepted_problem_elements)

            print(f"Total number of <tr> elements: {total_tr_count}")
            print(f"Number of <tr> elements with class='accepted-problem': {accepted_problem_count}")

    except FileNotFoundError:
        print(f"\n❌ ERROR: The file '{file_path}' was not found.")
        print("Please make sure the file is in the same folder as the script and the name matches.")
    except Exception as e:
        print(f"\nAn error occurred: {e}")



def fetch_api_data(tag):
    url = f'https://codeforces.com/api/problemset.problems?tags={tag}'

    try:
        # Send an HTTP GET request to the API URL
        response = requests.get(url)

        # Raise an exception for bad status codes (4xx or 5xx)
        response.raise_for_status()

        # Convert the JSON response text into a Python dictionary
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


def filtered_problem(tag = 'geometry', rating_start = 0, rating_end = 4000):
    data = fetch_api_data(tag)
    problems = data['result']['problems']
    res = []
    for problem in problems:
        if 'rating' in problem.keys() and problem['rating'] >= rating_start and problem['rating'] <= rating_end:
            res.append(problem)

    return res

'''
from temp import filtered_problem
problems = filtered_problem('geometry',1500,2000)

'''