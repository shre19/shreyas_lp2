name = "Sales Bot"
mood = "good"

products = {
    "mouse": 500,
    "keyboard": 400,
    "laptop": 60000,
    "gaming laptop": 75000,
    "pc": 80000,
    "cpu": 40000,
    "gaming chair": 15000,
    "earphones": 500,
    "headphones": 1000
}

def getProducts(products):
    s = "We have all kinds for electronics like "
    for k in products:
        s += k
        s+= ", "
    return s

responses = {
    "what is your name?": 
    "My name is {0}.".format(name),
    "how are you?": 
        "I am feeling {0}.".format(mood),
    "bye":
        "Bye bye have a lovely day :)",
    "default": 
        "Sorry I have no information about this please call out customer care number 1800-900-800.",
    "contact": "You can call to our customer representative on 1800-900-800",
    "product": getProducts(products)
    
}

def give_price(product):
    for k, v in products.items():
        if k == product:
            return v
    return "default"


def match(curr_text):
    if "name" in curr_text:
        new_text = "what is your name?"
    elif "how are" in curr_text:
        new_text = "how are you?"
    elif "price" in curr_text:
        s = curr_text.split("price of")[1].strip()
        new_text = give_price(s)
    elif "want" in curr_text:
        s = curr_text.split("want")[1].split(" ")[-1].strip()
        new_text = give_price(s)
    elif "bye" in curr_text:
        new_text = "bye"
    elif "contact" in curr_text:
        new_text = "contact"
    elif 'product' in curr_text:
        new_text = "product"
    else:
        new_text = "default"
    return new_text

def res(message):
    if message in responses:
        new_message = responses[message]
    else:
        new_message = responses["default"]
    return new_message

print("chatbot : Hi there, Welcome to xyz electronics. how can i help you?")
while 1:
    user_input = input()
    
    user_input = user_input.lower()
    related_input = match(user_input)
    if(type(related_input) == int):
        related_input = "Price of that product will be {0}.".format(related_input)
        print("chatbot : " + str(related_input))
        print()
    else:
        op_message = res(related_input)
        print("chatbot : " + str(op_message))
        print( )
        if("bye" in op_message):
            break
    
