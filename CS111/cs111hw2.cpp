#include <iostream>
#include <vector>
#include <cmath>

using namespace std; 


// map decrypted integer to character
char mapping(int decrypted) {
    if (decrypted >= 7 && decrypted <= 32) {return 'A' + (decrypted - 7);}
    if (decrypted == 32) { return ' '; }
    if (decrypted == 33) { return '\"';}
    if (decrypted == 34) {return ',';}
    if (decrypted == 35) {return '.';}
    if (decrypted == 36) {return '\'';}

    return '?'; //  unmapped values
}

// Euclid Algorithm
int euclid(int a, int b) {
    if (a == b) {
        return a;
    }
    if (a > b) {
        return euclid(a - b, b);
    } else {
        return euclid(a, b - a);
    }
}
    // C^d mod n = (C mod n * C^{d-1}) mod n
int decryption(int number, int d, int n) {
    int result = 1;
    number = number % n;
    while (d > 0) {
        if (d % 2 == 1) {
            result = (result * number) % n;
        }
        d /= 2;
        number = (number * number) % n;
    }
    return result;
}

int main() {
    vector<int> encryptedMessage;
    vector<int> decryptedMessage;
    string decrytptedinWords;
    int m = 0; 
    int ciphertext = 0;

    int p, q, phiN, n, e, d, cnt1, cnt2 = 0;
    //cin everything 
    cin >> e >> n >> m; 
    for (int i=0; i < m; ++i) {
        cin >> ciphertext;
        encryptedMessage.push_back(ciphertext);
    }

    //check if public key is valid. if not, cout "Publiv key is not valid!" and quit program 
    for (int i = 1; i <= q; i++) {
        if (n % i == 0){
            cnt1++;}
    }
    for (int i = 1; i <= p; i++) {
        if (n % i == 0)
            cnt2++;
    }
     if (p == 0 || q == 0 || p == q || cnt1 >2 || cnt2 > 2) {
        cout << "Public key is not valid!" << endl;
        return 1;
    }

    //if pub key valid, decode 
    n = p*q;
    phiN = (p - 1) * (q - 1);

        //(d*e mod phi(n) )= 1)
    for (int i = 1; d != i ; i++) {
        if ((i * e) % phiN == 1) {
            d = i;
        }
    }

    //cout the p q and phi n and d, then on newline 
    cout << "p: " << p << ", q: " << q << ", phi(n): " << phiN << ", d: " << d << endl;
    
    //cout the decoded message in ints (decode and cout) 
   int decrypted; 
    for (int i = 0; i < m; i++) {
        decrypted = decryption(encryptedMessage.at(i), d, n);
        decryptedMessage.push_back(decrypted);
    }
    cout << endl;
    cout << "Decrypted message: ";
    for (int i = 0; i < m; i++) {
        cout << decryptedMessage.at(decrypted);
    }
    //on new line output english decoded message, chars should be all uppercase and mapped as same as hw 
    cout << endl;
    for (int i=0; i < encryptedMessage.size(); ++i) {
        decryptedMessage.at(i) = mapping(decryptedMessage.at(i)); 
    }

    return 0;
    
}


