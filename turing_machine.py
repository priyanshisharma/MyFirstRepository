def action(input_char, replace_with, move, new_state):
    global tapehead, state
    if tape[tapehead] == input_char:
        tape[tapehead] = replace_with
        state = new_state
        if move == 'L':
            tapehead -= 1
        else:
            tapehead += 1
        return True
    return False

string = input("Enter String: ")
length = len(string) + 2
tape = ['B']*length
i = 1
tapehead = 1
for s in string: #loop to place string in tape
    tape[i] = s
    i += 1

state = 0
#assigning characters to variable so that don't have to use characters each time
zero, one, X,  R, Y, B  = '0', '1', 'X', 'R', 'Y', 'B'
oldtapehead = -1
accept = False
while(oldtapehead != tapehead): #if tapehead not moving that means terminate Turing machine
    oldtapehead = tapehead
    print(tape , "with tapehead at index", tapehead, "on state" , state)
    
    if state == 0:
        if action(zero, X, R, 1):
            pass
        elif action(one,one,R,0) or action(B,B,R,0):
            break

    elif state == 1:
        if action(one, Y, R, 1) or action(zero, X, R, 2):
            pass
        elif action(B,B,R,1):
            break

    elif state == 2:
        if action(B,B,R,"ACCEPT"):
            pass
        elif action(one,one,R,2) or action(zero,zero,R,2):
            break  

    else:
        accept = True
        
            
if accept:
    print("String accepted on state = ", state)
else:
    print("String not accepted on state = ", state)