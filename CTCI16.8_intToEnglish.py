'''
Originally I was thinking ot use map


'''

smalls =["", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
"Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
"Sixteen", "Seventeen", "Eighteen", "Nineteen"]
tens =["", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy",
"Eighty", "Ninety"]
big = ["", "Thousand", "Million", "Billion"]



def intToEnglish(number):
    word =""
    bigNum =[]

    if number == 0:
        word = "zero"
        print(word)
        quit()

    for i in range(3, -1,-1):
        n=int(number/(1000**i))
        number=number%(1000**i)
        bigNum.append(n)


        if(n!=0):
            if (int(n/100)>0 ):
                word += smalls[int(n/100)]
                word +=" "
                word += "Hundred"
                word += " "
                n=n%100

            if(int(n/20)>0):
                word += tens[int(n/10)]
                word += " "
                # word += smalls[int(n%10)]
                # word += " "
                n = n%10

            if(n<20 and n>0):
                word += smalls[n]
                word += " "

            word +=big[i]
            word += " "

    print(word)

if __name__ =="__main__":
    intToEnglish(100030000)
