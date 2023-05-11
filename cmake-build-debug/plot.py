from matplotlib import pyplot as plt

if __name__ == "__main__":

    n_arr = []
    value_arr = []
    with open('neighborhood.txt') as data:
        for line in data:
            row = line.split()
            if row:
                value_arr.append(float(row[1]))
                n_arr.append(int(row[0]))
    print(n_arr)
    n = int (len(n_arr) / 3)
    print(n)
    plt.title("Result vs. Sample size")
    plt.xlabel("n")
    plt.ylabel("result")
    plt.plot(n_arr[0:n-1], value_arr[0:n-1], label="Adjacent Interchange")
    plt.plot(n_arr[n:2*n-1], value_arr[n:2*n-1], label="Insert")
    plt.plot(n_arr[2*n:3*n-1], value_arr[2*n:3*n-1], label="Swap")
    plt.legend()
    plt.show()
