import nltk
from nltk.chat.util import Chat

pairs = [
    [
        r"my name is (.*)",
        ["Hello %1, How are you today ?",]
    ],
    [
        r"hi|hey|hello",
        ["Hello", "Hey there",]
    ], 
    [
        r"what is your name ?",
        ["I am a bot created by Analytics sagar. you can call me crazy!",]
    ],
    [
        r"how are you ?",
        ["I'm doing good  How about You ?",]
    ],
    [
        r"sorry (.*)",
        ["Its alright","Its OK, never mind",]
    ],
    [
        r"I am fine",
        ["Great to hear that, How can I help you?",]
    ],
    [
        r"i'm (.*) doing good",
        ["Nice to hear that","How can I help you?:)",]
    ],
    [
        r"(.*) age?",
        ["I'm a computer program dudenSeriously you are asking me this?",]
    ],
    
    [
        r"(.*) created ?",
        ["sagar created me using Python's NLTK library ","top secret ;)",]
    ],
    [
        r"(.*) (location|city) ?",
        ['pune, Maharashtra',]
    ],
    
    [
        r"i work in (.*)?",
        ["%1 is an Amazing company, I have heard about it. But they are in huge loss these days.",]
    ],
    [
        r"i am looking for online guides and courses to learn data science, can you suggest?",
        ["Crazy_Tech has many great articles with each step explanation along with code, you can explore"]
    ],
    [
        r"quit",
        ["BBye take care. See you soon :) ","It was nice talking to you. See you soon :)"]
    ],
]

def chat():
    print("Hi! I am a chatbot created by sagar")
    chat = Chat(pairs)
    chat.converse()
#initiate the conversation
if __name__ == "__main__":
    chat()