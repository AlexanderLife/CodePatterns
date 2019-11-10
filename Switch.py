#Python Dictionaries: Pointers, Switch, Overloading Functions File0

#Goal:

a = 1

b = a

a = 2

print(b)

# output: 2

# Actual output: 1


# Way to Do it:

a = {}

a[0] = 1

b = a

a[0] = 2

print(b[0])

# output: 2


# all sorts of things can go into the key and value of a dictionary. like Functions.:

cat,dog = 1,2

def GetCat(): return cat

def GetDog(): return dog

a[GetCat]=GetDog

# notice we do not use the () because we want the Function it's self not the result of the function

print(a[GetCat]() )

#output: 2 # because it ran dog.


# We can use this to fake a switch case statement:

def CaseA(): print("""Case A""")

def CaseB(): print("""Case B""")

def CaseC(): print("""Case C""")

def CaseDefault(): print("""default""")

switch ={"a":CaseA,"A":CaseA,"b":CaseA,"B":CaseA,"c":CaseA,"C":CaseA}

def TheSwitchCase(Check):

    if Check in switch:

        return switch[Check]()

    else:

        return CaseDefault()


TheSwitchCase("A")

# output: Case A

TheSwitchCase("a")

# output: Case A

TheSwitchCase("k")

# output: default

# You can change the case at run-time, for WowCool or OhThatsbad.

def WowCool(): print("""Wow Cool""")

def OhThatsbad(): print("""Oh That's bad""")

switch["A"]=WowCool

TheSwitchCase("A")

# output: Wow Cool

switch["b"]=OhThatsbad

TheSwitchCase("b")

# output: Oh That's bad

# let's make a new file and the switch with arguments to it's functions.
