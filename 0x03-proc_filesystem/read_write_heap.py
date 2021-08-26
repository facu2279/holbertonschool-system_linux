#!/usr/bin/python3
""" Made by Facundo Diaz for Holberton School 2021"""
import sys

def isascii_encodable(string):
    """ """
    try:
        string.encode("ASCII")
        return True
    except UnicodeEncodeError:
        return False

def cambiar():
    """ """
    if (len(sys.argv) != 4):
        print("Usage: ./read_write_heap [pid]"
              " [search_string] [replace_string]")
        exit(1)
    if not to_int(sys.argv[1]):
        print("{} must be an integer".format(sys.argv[1]))
        exit(1)
    [(print("{} must be ascii".format(x)), exit(1)) for x in sys.argv[2:]
        if not isascii_encodable(x)]
    return (int(sys.argv[1]), sys.argv[2].encode("ASCII"),
            sys.argv[3].encode("ASCII"))

def to_int(num):
    """ """
    try:
        int(num)
        return True
    except ValueError:
        return False

def posiciones(pid):
    """ """
    try:
        with open("/proc/{}/maps".format(pid)) as map_file:
            for line in map_file:
                if line.endswith("[heap]\n"):
                    return (int(x, 16) for x in line.split()[0].split("-"))
            print("Heap memory wasn't found")
            exit(1)
    except Exception as err:
        print("Error in maps: {}".format(err))
        exit(1)

def escribir(pid, search_bytes, replace_bytes, heap_start, heap_end):
    """ """
    try:
        with open("/proc/{}/mem".format(pid), "r+b") as mem_file:
            mem_file.seek(heap_start)
            print("Heap size: {}".format(heap_end - heap_start))
            data = mem_file.read(heap_end - heap_start)
            data_pos = data.find(search_bytes)
            if data_pos == -1:
                print("The string {} is not in the heap".format(search_bytes))
                exit(1)
            if (heap_start + data_pos + len(replace_bytes)) + 1 > heap_end:
                print("The replace {} overlaps the heap".format(replace_bytes))
                exit(1)
            print("Found in byte: 0x{:02x}".format(heap_start + data_pos))
            mem_file.seek(heap_start + data_pos)
            mem_file.write(replace_bytes + b'\x00')
    except Exception as err:
        print("Error in mem: {}".format(err))
        exit(1)

def main():
    pid, search_bytes, replace_bytes = cambiar()
    print("{} for {} in PID {}".format(search_bytes, replace_bytes, pid))
    heap_start, heap_end = posiciones(pid)
    print("Heap bytes: 0x{:02x} - 0x{:02x}".format(heap_start, heap_end))
    escribir(pid, search_bytes, replace_bytes, heap_start, heap_end)

if __name__ == "__main__":
    main()