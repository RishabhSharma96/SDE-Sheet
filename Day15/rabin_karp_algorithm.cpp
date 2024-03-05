/////// RABIN KARP ALGO

class Solution {
private:
    const int PRIME = 101;

    double calculateHash(string str) {
        double hash = 0;
        for (int i = 0; i < str.length(); i++) {
            hash += str[i] * pow(PRIME, i);
        }
        return hash;
    }

    double updateHash(double prevHash, char oldChar, char newChar, int patternLength) {
        double newHash = (prevHash - oldChar) / PRIME;
        newHash = newHash + newChar * pow(PRIME, patternLength - 1);
        return newHash;
    }

    int search(string text, string pattern) {
        int patternLength = pattern.length();
        double patternHash = calculateHash(pattern);
        double textHash = calculateHash(text.substr(0, patternLength));
        int count = 0;

        for (int i = 0; i <= text.length() - patternLength; i++) {
            if (textHash == patternHash) {
                if (text.substr(i, patternLength) == pattern) {
                    count++;
                }
            }

            if (i < text.length() - patternLength) {
                textHash = updateHash(textHash, text[i], text[i + patternLength], patternLength);
            }
        }

        return count;
    }
};




///////// QUESTION BASED ON IT

class Solution {
private:
    const int PRIME = 101;

    double calculateHash(string str) {
        double hash = 0;
        for (int i = 0; i < str.length(); i++) {
            hash += str[i] * pow(PRIME, i);
        }
        return hash;
    }

    double updateHash(double prevHash, char oldChar, char newChar, int patternLength) {
        double newHash = (prevHash - oldChar) / PRIME;
        newHash = newHash + newChar * pow(PRIME, patternLength - 1);
        return newHash;
    }

    int search(string text, string pattern) {
        int patternLength = pattern.length();
        double patternHash = calculateHash(pattern);
        double textHash = calculateHash(text.substr(0, patternLength));
        int count = -1;

        for (int i = 0; i <= text.length() - patternLength; i++) {
            if (textHash == patternHash) {
                if (text.substr(i, patternLength) == pattern) {
                    if(count == -1){
                        count = 1;
                    }
                    else{
                        count++;
                    }
                }
            }

            if (i < text.length() - patternLength) {
                textHash = updateHash(textHash, text[i], text[i + patternLength], patternLength);
            }
        }

        return count;
    }

public:
    int repeatedStringMatch(string A, string B) {
        if(A == B) return 1;
        int count = 1;
        string source = A;
        while(source.size() < B.size()){
            count++;
            source+=A;
        }
        if(source == B) return count;
        if(search(source,B) != -1) return count;
        if(search(source+A,B) != -1) return count+1;
        return -1;
    }
};