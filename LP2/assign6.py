
common_symp = []

def covid_test():
    global level
    global cnt
    level = 0
    cnt = 0
    
    print("These are the serious symptomps if you have any of them you should see a doctor immediately")
    print('Enter yes or no')
    user_input = input("Are you facing difficulty breathing or shortness of breath? ")
    user_input1 = input("Are you facing difficulty breathing or shortness of breath? ")
    user_input2 = input("Are you facing difficulty breathing or shortness of breath? ")

    if user_input =="yes" or user_input1 == "yes" or user_input2 == "yes":
        return "danger"

    print("\nThese are the common symptoms of covid-19\n")
    print("Enter   0. No symptomps \n\t1. Low symptomps \n\t2. Medium Symptoms \n\t3. Severe Symptomps")
    user_input = input("Do you have fever? ")
    if user_input != 0:
        common_symp.append("fever")
        level += int(user_input)
        cnt+=1

    user_input = input("Do you have cough? ")
    if user_input != 0:
        common_symp.append("cough")
        level += int(user_input)
        cnt+=1

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
    
    print("\nThese are the less common symptomps of covid 19\n")
    print("1. sore throat\n2. headache\n3. aches and pains\n4. diarrhoea \n5. a rash on skin, or discolouration of fingers or toes\n6.red or irritated eyes")
    user_input = input("\nEnter number of how many of the above mentioned symptomps you are facing?" )
    cnt += int(user_input)
    level += int(user_input) 
    
    return "no_danger"

def analysis():
    result = covid_test()
    if result == "danger":
        print("\nSeek immediate medical attention cause you are facing some of the serious symptoms. Call 112 for ambulence.")
    else:
        if cnt >=6 and len(common_symp) >=2 or level >=10:
            print("\nYou have medium level symptomps of covid-19. Please visit a nearby doctor and isolate yourself from others.")

        elif cnt>=4 and len(common_symp) >= 1 or level>=5:
            print("\nYou have very mild symptomps of covid 19. Please see a doctor and isolate yourself from others.")
        elif cnt>=2 and len(common_symp)>=1:
            print("\nThere is a very less possibilty that you have covid. Please visit a nearby doctor")
        else:
            print("\nYou do not have covid-19. Please consider visiting doctor for your treatment.")   
              
analysis()