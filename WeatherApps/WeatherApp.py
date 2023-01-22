import requests

api_key = '45e00a340a4d5bd9758f3f03e4d80a36'

user_input = input("Enter City: ")

weather_data = requests.get(
    f"https://api.openweathermap.org/data/2.5/weather?q={user_input}&units=imperial&APPID={api_key}")

if weather_data.json()['cod'] == '404':
    print("City Not Found")
else:
    weather = weather_data.json()['weather'][0]['main']
    temp = round(weather_data.json()['main']['temp'])
    feelsLike = round(weather_data.json()['main']['feels_like'])
    
    if (weather == 'Clouds') :
        weather = "Cloudy"
    if (weather == 'Rain') :
        weather = "Rainy"
    if (weather == 'Mist') :
        weather = "Misty"   

    print(f"The weather in {user_input} is {weather}")
    print(f"The temperature in {user_input} is {temp}°F")
    print(f"However, the temperature feels like {feelsLike}°F outside")

