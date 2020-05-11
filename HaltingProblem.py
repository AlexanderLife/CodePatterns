#This is a response to a Tom Scott video Are "There Problems That Computers Can't Solve?" https://youtu.be/eqvBaj8UYz4

#1
Code="""While True:"""

#2
DoesItHalt = lambda DeadArgument,CodeToCheck: True if CodeToCheck.find("While True:",0)==-1 else False

#3
def Opposite(HaltDetector,CodeToCheck):
    """
    This is to show that the Halting problem is not a Logical Paradox, it is simply a infinite loop. it may be a infinite loop of Recursion.
    but it is no more of a paradox then While True. perhaps infinite loop are
    Paradoxes if so this starts to show that.

    the system is to practically handle logical paradoxes that you might face in your
    programs with individual exceptions as they are cause in your program.
    
    notice how the "DoesItHalt" takes in a DeadArgument that is not used.
    oddly the DeadArgument this is required. This is so we can Use this "Opposite"
    function that requires two arguments.

    the logic of it might halt if you had more computer power to do the recursion.
    this is the same as a while loop that counts beyond the limits of the machine,
    if only the circuits didn't rust away first. so the halting problem combined
    with entropy is a paradox. to keep that program from halting you must keep it
    running, how physically? 

    so now you say not a actual machine that suffers from rust and other entropy.
    that lives in nature. it is now a philosophy machine that does not halt the
    program and is powered by a perpetual motion machine and does not halt due to
    entropy. OK that's fine but let's say the unlimited computer can preform all
    calculations instantly. It's unrestricted so then 2 will work twice as fast
    and a infinite number of them will work instantly. so now we know for sure if
    the code will run forever because if it takes any time to run it will take all
    time to run. even if do things like put it in a Recursion Loop.

    If your unlimited your unlimited if your limited your limited.
    The halting problem Opposite boxes is a fallacy of oversimplification.

    So if we are practically limited by heat death of the universe on our Matrioshka
    brain, then we misewell be limited by the Python Interpreter on my old computer.
    it's basically the same-thing.

    By Alexander Sloka
    """
#4
    try:#<--Paradox Absorbing Crumple Zone
#5
        if HaltDetector(HaltDetector,CodeToCheck):
#6
            while True:
#7
                print("Something Rude")
#8
    except RecursionError:
#9
        print("Recursion Loop to the extent of the Python Interpreter.\nI am sure it would have halted sometime between now and\nThe Heat Death Of The Universe. so it was stoped early.")

#10
Opposite(Opposite,Code)

#11
#Opposite(Opposite,"Anything")

