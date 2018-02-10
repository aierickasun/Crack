This program, written in c, utilizes the brute force dictionary attack against
a ciphertext encrypted by a one way hash. Specifically by the function crypt.
This one way hash function utilizes a key and salt. Note, however, that given the
 ciphertext, the first 2 bytes(characters) is the salt itself. So if the hash was (ab[11 random chars]), the 
 salt would be ab. So you would use ab as the salt along with the words of the dictionary.
 Useful File read Terminators: 
 https://stackoverflow.com/questions/1835986/how-to-use-eof-to-run-through-a-text-file-in-c
 A little mishap, when comparing strings, simply doing (str1 == str2) doesn'twork since that's just comparing
 The pointers(memory locations) of the two strings, which will obviously be false.
 Instead, opt for suing strcmp(check, input)==0;..