#간단한 가위바위보 구현하기

a = "가위"
b = "바위"

def RCP(a,b):
    if(a=="가위"):
        if(b=="바위"):
            print("b가 이김")
        else:
            print("a가 이김")
    elif(a=="바위"):
        if(b=="보"):
            print("b가 이김")
        else:
            print("a가 이김")
    elif(a=="보"):
        if(b=="가위"):
            print("b가 이김")
        else:
            print("a가 이김")        
    
if(a == b):
    print("비김")
else:
    RCP(a,b)