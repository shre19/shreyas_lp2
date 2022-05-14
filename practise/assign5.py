name = "Sales bot"
mood = "Good"

products = {
    "mouse": 400,
    "keyboard": 600,
    "laptop": 70000,
    "pc": 80000,
    "Gaming laptop": 75000,
    "cpu": 40000,
    "gaming chair": 13000,
    "earphones": 1000,
    "headphones": 2500
}

def getProducts():
    s = "The available products are "
    for k, v in products.items():
        s += k 
        s+=", "
    return s

responses = {
    "What is your name?": "My name is {0}.".format(name),
    "How are you?": "I am feeling {0}".format(mood),
    "bye" : "Bye bye have a lovely day!",
    "product": getProducts(),
    "contact": "You can call our customer representative on 1800-900-800",
    "default": "Sorry I have no information about this, please call our customer care number 1800-900-800",
}

def give_price(product):
    for k, v in products.items():
        if k == product:
            return v
    return "default"    

def match(curr_text):
    if "name" in curr_text:
        new_text = "What is your name?"
    elif "how are" in curr_text:
        new_text = "How are you?"
    elif "bye" in curr_text:
        new_text = "bye"
    elif "product" in curr_text:
        new_text = "product"
    elif "price" in curr_text:
        s = curr_text.split("price of")[1].strip()
        new_text = give_price(s)
    elif "want" in curr_text:
        s = curr_text.split(" ")[-1].strip()
        new_text = give_price(s)
    elif "contact" in curr_text:
        new_text = "contact"
    else:
        new_text = "default"
    return new_text

def res(message):
    if message in responses:
        return responses[message]
    else:
        return responses["default"]

print("Charbot: Hi there, welcome to x electronics. How can i help you?\n")

while 1:
    user_input = input()
    user_input = user_input.lower()

    related_input = match(user_input)
    if(type(related_input) == int):
        related_input = "Price of that product will be {0}.".format(related_input)
        print("Chatbot: "+str(related_input))
        print()
    else:
        op_message = res(related_input)
        print("Chatbot: "+ op_message)
        print()
        if("bye" in op_message):
            break;