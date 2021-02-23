import json
import sys

if __name__ == "__main__":
    if len(sys.argv) !=2:
        print("usage: %s <json file>" % (sys.argv[0]))
        exit(1)
    with open(sys.argv[1]) as f:
        data = json.load(f)


    print("type data after json.load: %s size %d" % (str(type(data)), len(data)))
    instr = input("input node :")
    while instr != "exit" :
        node = data.get(instr)
        print(node)
        if type(node) is dict:
            print("node : %s (has children %d) : "% (str(type(node)), len(node)))
            for x in node:
                print("%s  : %s "% (x, json.dumps(node[x])))
        else:
            print("node : %s  : %s " % (str(type(node)), node))
        instr = input("input node :")
    exit(0)