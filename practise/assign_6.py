
common_symp = []

def covid_test():
    global level
    global count
    level = 0
    count = 0

    print("These are the serious symptomps if you have any of these please seek medical attention")
    print("Enter yes or no: ")
    user_input = input("Are you facing difficulty in breathing")
    user_input1 = input("Aer you facing loss of speech")
    user_input2 = input("are you facing chest pain")

    if user_input =="yes" or user_input1 == "yes" or user_input2 == "yes":
        return "danger"

    print("These are the common symptomps of the covid-19\n")
    print("Enter    0.No symptomps \n\t 1.Low symptomps \n\t 2.Medium symptoms \n\t 3.Severe symptomps")

    user_input = "Do you have fever "
    if user_input != 0:
        common_symp.append("fever")
        level += user_input
        count += 1

    user_input = "Do you have cough "
    if user_input != 0:
        common_symp.append("cough")
        level += user_input
        count += 1

    user_input = input("Do you have tiredness? ")
    if user_input != 0:
        common_symp.append("tiredness")
        level += int(user_input)
        cnt+=1

    user_input = input("Are you facing loss of taste or smell? ")
    if user_input != 0:
        common_symp.append("loss of taste")
        level += int(user_input)
        cnt+=1

    print("These are the less common symptomps of covid-19\n")
    print("1. Sore throat 2.Headache 3. aches and pain 4.Diarrheoa 5.a rash on skin 6.red or irritated eyes")
    user_input = input("How many number of above mentinoed symptoms are you facing?")
    cnt += user_input
    level += user_input

    return "no_danger"

def analysis():
    result = covid_test()
    if result == "danger":
         print("\nSeek immediate medical attention cause you are facing some of the serious symptoms. Call 112 for ambulence.")
    else:
        print("Medium level, mild level, less possibility, Do not have covid 19")

analysis()