import sys
import csv

# check arguments
if len(sys.argv) != 3:
    sys.exit("Usage: python dna.py data.csv sequence.txt")

# open and read dna sequences from txt files
with open(sys.argv[2]) as dnaFile:
    dnaReader = csv.reader(dnaFile)
    for row in dnaReader:
        dnaList = row

# store lists of dna into a string
dna = dnaList[0]

# dict for all of the sequences
sequences = {}

# open and read csv files then assign into a list
with open(sys.argv[1]) as peepsFile:
    peep = csv.reader(peepsFile)
    for row in peep:
        dnaSequences = row
        dnaSequences.pop(0)
        break

# copy list of dna sequence into a dict
for sequence in dnaSequences:
    sequences[sequence] = 1

# if repetitions of the values from sequence dictionary are found, count
for i in sequences:
    l = len(i)
    tmpMax = 0
    tmp = 0
    for j in range(len(dna)):
        # after having counted a sequence
        # skip at the end of it to avoid counting again
        while tmp > 0:
            tmp -= 1
            continue
# if the segment of dna corresponds to the key && there is a repetition of it
        # increment counter
        if dna[j: j + l] == i:
            while dna[j - l: j] == dna[j: j + l]:
                tmp += 1
                j += l
# compare the value to the previous longest sequence && if it is longer it becomes the new max
            if tmp > tmpMax:
                tmpMax = tmp
# store the longest sequences in the dictionary using the correspondent key
    sequences[i] += tmpMax

with open(sys.argv[1], newline='') as peepsFile:
    peep = csv.DictReader(peepsFile)
    for person in peep:
        match = 0
        # compares the sequences to every person and prints name, if match then exit
        for dna in sequences:
            if sequences[dna] == int(person[dna]):
                match += 1
        if match == len(sequences):
            print(person['name'])
            sys.exit()
    # if there is no match then prints no match then exit
    print("No match")
    sys.exit()