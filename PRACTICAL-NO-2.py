SetA = [] 
SetB = [] 
def insert(s, element): 
    if element not in s: 
        s.append(element) 
def display(s): 
    print("Set elements:", s) 
def union(set1, set2): 
    return list(set(set1 + set2)) 
def intersection(set1, set2): 
    return [x for x in set1 if x in set2] 
def difference(set1, set2): 
    return [x for x in set1 if x not in set2] 
def find(s, element): 
    return element in s 
def remove(s, element): 
    if element in s: 
        s.remove(element) 
def size(s): 
    return len(s) 
 
def is_subset(set1, set2): 
    return all(elem in set2 for elem in set1) 
 
if __name__ == "__main__": 
    while True: 
        print("\n--- SET ADT MENU ---") 
        print("1. Insert element to SetA") 
        print("2. Insert element to SetB") 
        print("3. Remove element from SetA") 
        print("4. Find element in SetA") 
        print("5. Display Sets") 
        print("6. Union") 
        print("7. Intersection") 
        print("8. Difference (SetA - SetB)") 
        print("9. Check if SetB is a subset of SetA") 
        print("10. Exit") 
        choice = int(input("Enter choice: ")) 
 
        if choice == 1: 
            element = int(input("Enter element: ")) 
            insert(SetA, element) 
        elif choice == 2: 
            element = int(input("Enter element: ")) 
            insert(SetB, element) 
        elif choice == 3: 
            element = int(input("Enter element to remove from SetA: ")) 
            remove(SetA, element) 
        elif choice == 4: 
            element = int(input("Enter element to find in SetA: ")) 
            print("Element found" if find(SetA, element) else "Element not found") 
        elif choice == 5: 
            print("SetA:", end=" ") 
            display(SetA) 
            print("SetB:", end=" ") 
            display(SetB) 
        elif choice == 6: 
            print("Union:", union(SetA, SetB)) 
        elif choice == 7: 
            print("Intersection:", intersection(SetA, SetB)) 
        elif choice == 8: 
            print("Difference (SetA - SetB):", difference(SetA, SetB)) 
        elif choice == 9: 
            print("SetB is a subset of SetA" if is_subset(SetB, SetA) else "SetB is not a subset of SetA") 
        elif choice == 10: 
            break 
        else: 
            print("Invalid choice!")