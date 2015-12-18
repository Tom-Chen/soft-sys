lookupTable = {};

def CheckParity(longs):
    results = []

    for long in longs:
        print("Running loop")
        preComputed = lookupTable.keys()

        if long in preComputed:
            print("previously computed number")
            results.append(lookupTable[long])
        else:
            print("new number")
            parity = 0;
            for digit in bin(long)[2:]:
                parity += int(digit,2)
            parity = parity % 2
            lookupTable[long] = parity;
            results.append(parity)

    return results

test = [0b0101101010101010001011111010100111111001010111010011010000110101, 0b0101101010101010001011111010100111111001010111010011010000110101]

print(CheckParity(test))