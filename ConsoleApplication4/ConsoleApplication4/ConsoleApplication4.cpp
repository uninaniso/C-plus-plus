#include <iostream>
#include <string>

using namespace std;

class Morse {
public:
    static string encodeLetter(char letter) {
        letter = toupper(letter);
        switch (letter) {
        case 'A': return ".-";
        case 'B': return "-...";
        case 'C': return "-.-.";
        case 'D': return "-..";
        case 'E': return ".";
        case 'F': return "..-.";
        case 'G': return "--.";
        case 'H': return "....";
        case 'I': return "..";
        case 'J': return ".---";
        case 'K': return "-.-";
        case 'L': return ".-..";
        case 'M': return "--";
        case 'N': return "-.";
        case 'O': return "---";
        case 'P': return ".--.";
        case 'Q': return "--.-";
        case 'R': return ".-.";
        case 'S': return "...";
        case 'T': return "-";
        case 'U': return "..-";
        case 'V': return "...-";
        case 'W': return ".--";
        case 'X': return "-..-";
        case 'Y': return "-.--";
        case 'Z': return "--..";
        case '0': return "-----";
        case '1': return ".----";
        case '2': return "..---";
        case '3': return "...--";
        case '4': return "....-";
        case '5': return ".....";
        case '6': return "-....";
        case '7': return "--...";
        case '8': return "---..";
        case '9': return "----.";
        default: return "";
        }
    }

    static char decodeLetter(const string morse) {
        if (morse == ".-") return 'A';
        if (morse == "-...") return 'B';
        if (morse == "-.-.") return 'C';
        if (morse == "-..") return 'D';
        if (morse == ".") return 'E';
        if (morse == "..-.") return 'F';
        if (morse == "--.") return 'G';
        if (morse == "....") return 'H';
        if (morse == "..") return 'I';
        if (morse == ".---") return 'J';
        if (morse == "-.-") return 'K';
        if (morse == ".-..") return 'L';
        if (morse == "--") return 'M';
        if (morse == "-.") return 'N';
        if (morse == "---") return 'O';
        if (morse == ".--.") return 'P';
        if (morse == "--.-") return 'Q';
        if (morse == ".-.") return 'R';
        if (morse == "...") return 'S';
        if (morse == "-") return 'T';
        if (morse == "..-") return 'U';
        if (morse == "...-") return 'V';
        if (morse == ".--") return 'W';
        if (morse == "-..-") return 'X';
        if (morse == "-.--") return 'Y';
        if (morse == "--..") return 'Z';
        if (morse == "-----") return '0';
        if (morse == ".----") return '1';
        if (morse == "..---") return '2';
        if (morse == "...--") return '3';
        if (morse == "....-") return '4';
        if (morse == ".....") return '5';
        if (morse == "-....") return '6';
        if (morse == "--...") return '7';
        if (morse == "---..") return '8';
        if (morse == "----.") return '9';
        return ' ';
    }
};

class InformationEncoding {
    string code;

public:
    InformationEncoding(const string message) {
        code = encodeMessage(message);
    }

    string getCode() {
        cout << "\nCode: " << code;
        return code;
    }

    string encodeMessage(const string message) {
        string encodedMessage = "";
        //да я испозовал foreach
        for (char letter : message) {
            string morse = Morse::encodeLetter(letter);
            if (!morse.empty()) {
                encodedMessage += morse + " ";
            }
        }
        return encodedMessage;
    }
};

class DecodingInformation {
private:
    string originalString;

public:
    DecodingInformation(string morse) {
        originalString = decodeMessage(morse);
        cout << "Original String: " << originalString;
    }

    string decodeMessage(const string morse) {
        string decodedMessage = "";
        string currentMorse = "";
        for (char c : morse) {
            if (c != ' ') {
                currentMorse += c;
            }
            else {
                char letter = Morse::decodeLetter(currentMorse);
                if (letter != ' ') {
                    decodedMessage += letter;
                }
                currentMorse = "";
            }
        }
        char letter = Morse::decodeLetter(currentMorse);
        if (letter != ' ') {
            decodedMessage += letter;
        }
        return decodedMessage;
    }
};

int main() {
    InformationEncoding a = { "HEllO WORLD 1234567890" };
    string aCode = a.getCode();
    DecodingInformation b = { aCode };
}
