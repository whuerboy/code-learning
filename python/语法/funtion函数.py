oneInt = 0

def inputInt():
   a=int(input())
   while(a%2!=0 or a<6):
       a = int(input())
   global  oneInt
   oneInt=a

def isPrime(oneInt)->bool:
    for i in range(2, oneInt - 1):
        n = True
        if oneInt % i == 0:
            return  False
    return  True

def main():
    inputInt()
    result = [];
    global  oneInt
    for i in range(2,oneInt-1):
        if(isPrime(i) and isPrime(oneInt-i) and ((oneInt-i) not in result) ):
                result.append(i)
                print(f"{oneInt} = {i} + {oneInt-i}")


main()