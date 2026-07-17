import os
import time
import sys

h = 0
m = 0
s = 0


def clear_screen():
    os.system("cls" if os.name == "nt" else "clear")


def start(H, M, S):
    global h, m, s

    x, y, z = H, M, S
    count = 1

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

        if h == H and m == M and s == S:

            print("\n1. Continue")
            print("2. Stop")
            print("3. Restart")
            print("4. Exit")

            ch = int(input("\nEnter your choice: "))

            if ch == 1:
                count += 1
                H = count * x
                M = count * y
                S = count * z

            elif ch == 2:
                print(f"\nClock Stopped at {h:02d}:{m:02d}:{s:02d}")

                ck = int(input("Enter 1 to continue: "))

                if ck == 1:
                    count += 1
                    H = count * x
                    M = count * y
                    S = count * z
                else:
                    sys.exit()

            elif ch == 3:
                h = 0
                m = 0
                s = 0

                H = x
                M = y
                S = z
                count = 1

                print("\nClock Restarted!")
                time.sleep(1)

            elif ch == 4:
                sys.exit()

            else:
                print("\nInvalid Choice!")
                time.sleep(1)


def main():
    while True:
        print("\n===== DIGITAL CLOCK =====")
        print("Enter limited time (H M S):")

        H, M, S = map(int, input().split())

        print("\n1. Start Clock")
        print("2. Exit")

        opt = int(input("Enter your option: "))

        if opt == 1:
            start(H, M, S)

        elif opt == 2:
            print("Program Terminated.")
            break

        else:
            print("Invalid Option!")


if __name__ == "__main__":
    main()
