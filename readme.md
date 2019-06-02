Crack utilizes the brute force dictionary attack against a ciphertext encrypted by a one way hash; specifically, using the C function crypt.  
Crypt is a one way hash function that utilizes a key and salt. Note, however, that given the ciphertext, the first 2 bytes(characters) is the salt itself. So if the hash was (ab[11 random chars]), the salt would be ab.  
So you would use 'ab' as the salt along with the words of the dictionary to run the brute force attack.  
Useful File read Terminators: https://stackoverflow.com/questions/1835986/how-to-use-eof-to-run-through-a-text-file-in-c  
One small issue I ran into when comparing strings was that simply doing (str1 == str2) doesn't work because that is just comparing
the pointers (memory locations) of the two strings, which will obviously be false.  
Instead, opt for using "strcmp(check, input)==0" to compare the values between the two strings.
