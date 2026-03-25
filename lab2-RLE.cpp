#include iostream
#include string
#include cctype


  RLE Encode
 
stdstring rleEncode(const stdstring& input) {
    if (input.empty()) return ;

    stdstring result;
    result.reserve(input.size());  performance optimization

    int count = 1;

    for (size_t i = 1; i = input.size(); ++i) {
        if (i  input.size() && input[i] == input[i - 1]) {
            count++;
        } else {
            result += stdto_string(count);
            result += input[i - 1];
            count = 1;
        }
    }

    return result;
}


  RLE Decode
 
stdstring rleDecode(const stdstring& encoded) {
    stdstring result;
    size_t i = 0;

    while (i  encoded.size()) {
        if (!stdisdigit(encoded[i])) {
             invalid format → skip կամ treat as 1
            result += encoded[i++];
            continue;
        }

        int count = 0;

         build number
        while (i  encoded.size() && stdisdigit(encoded[i])) {
            count = count  10 + (encoded[i] - '0');
            i++;
        }

        if (i = encoded.size()) break;

        char ch = encoded[i++];

        result.append(count, ch);  շատ ավելի արագ քան for loop
    }

    return result;
}

int main() {
    stdstring original = AAABBBCCDEEEEEEEEEEEF;

    stdstring encoded = rleEncode(original);
    stdstring decoded = rleDecode(encoded);

    stdcout  Original   original  n;
    stdcout  Encoded    encoded  n;
    stdcout  Decoded    decoded  n;
    stdcout  Match      (original == decoded  True  False)  n;

    return 0;
}
