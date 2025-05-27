import requests

username = "ar363"  # ← Replace with your GitHub username
url = f"https://api.github.com/users/{username}/repos"
response = requests.get(url)

if response.status_code == 200:
    repos = response.json()
    latest_five = sorted(repos, key=lambda x: x['created_at'], reverse=True)[:5]
    for repo in latest_five:
        print("Name:", repo['name'])
        print("Created at:", repo['created_at'])
        print("Language:", repo.get('language', 'None'))
        print("---")
else:
    print("Failed to fetch data:", response.status_code)

