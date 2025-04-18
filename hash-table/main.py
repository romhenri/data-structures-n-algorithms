from HashTableDouble import HashTableDouble

if __name__ == "__main__":
    tabela = HashTableDouble(n=100)

    # Insert
    tabela.insert("nando", 25)
    tabela.insert("luis", 30)
    tabela.insert("edu", 22)
    tabela.insert("rauana", 19)
    tabela.insert("larissa", 40)
    tabela.insert("muriele", 28)
    tabela.insert("guilherme", 35)

    # Search
    print("nando:", tabela.search("nando"))
    print("edu:", tabela.search("edu"))
    print("rauana:", tabela.search("rauana"))
    print("larissa:", tabela.search("larissa"))
    print("none1:", tabela.search("sofia")) 
    print("none12:", tabela.search("marco"))
    print("none13:", tabela.search("julia"))
