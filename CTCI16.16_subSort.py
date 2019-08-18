
def subSort(arr):
    left= 1
    right = len(arr)

    while(arr[left-1]<=arr[left]): left+=1
    while(arr[right-1]>=arr[right-2]):right-=1


    min = arr[left-1]
    max = arr[right]

    for j in range(left, right+1):
        if arr[j]<min:
            min = arr[j]

        if arr[j]>max:
            max=arr[j]

    while(min<=arr[left-1] and left>0): left-=1
    while(max>=arr[right+1] and right<len(arr)-1): right+=1

    print(left)
    print(right)



if __name__ =="__main__":
    arr = [1,2,8,7,10,2,16,17,18]
    subSort(arr)

# for i in range(len(arr)):
    #     while(arr[i]<arr[i+1]): left+=1
    #     while(arr[len(arr)-1-i]>arr[len(arr)-2-i]): right-=1
    #
    #     min = arr[left-1]
    #     max = arr[right +1]
    #
    #     for j in range(left, right+1):
    #         if arr[j]<min:
    #             min = arr[j]
    #
    #         if arr[j]>max:
    #             max=arr[j]
    #
    # while(min>=arr[left]): left-=1
    # while(max<=arr[right]): right+=1
    #
    # print(left)
    # print(right)