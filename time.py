import time
import os
import sys

h = 0
m = 0
s = 0


def clear_screen():
    os.system("cls" if os.name == "nt" else "clear")


def start(lim):
    global h, m, s

    while True:
        clear_screen()

        print(f"CLOCK : {h:02d}:{m:02d}:{s:02d}")

        time.sleep(1)

        s += 1

        if s == 60:
            s = 0
            m += 1

        if m == 60:
            m = 0
            h += 1

        if h == 24:
            h = 0

        # Ask the user every 'lim' seconds
        if s % lim == 0:
            print("\n1. Continue")
            print("2. Stop")
            print("3. Restart")
            print("4. Exit")

            ch = int(input("\nEnter your choice: "))

            if ch == 1:
                continue

            elif ch == 2:
                print(f"\nClock Stopped at {h:02d}:{m:02d}:{s:02d}")
                time.sleep(2)
                return

            elif ch == 3:
                h = 0
                m = 0
                s = 0

                print("\nClock Restarted!")
                time.sleep(1)

            elif ch == 4:
                print("Program Terminated.")
                sys.exit()

            else:
                print("Invalid Choice!")
                time.sleep(1)


def main():
    while True:
        print("\n===== DIGITAL CLOCK =====")

        lim = int(input("Enter limit: "))

        print("1. Start Clock")
        print("2. Exit")

        opt = int(input("Enter your option: "))

        if opt == 1:
            start(lim)

        elif opt == 2:
            print("Program Terminated.")
            break

        else:
            print("Invalid Option!")


main()