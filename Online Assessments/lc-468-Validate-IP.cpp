class Solution {
public:
    string validIPAddress(string IP) {
        if(is_ipv4(IP))
            return "IPv4";
        if(is_ipv6(IP))
            return "IPv6";
        return "Neither";
    }
    
    bool is_ipv4(string IP){
        if(count(IP.begin(), IP.end(), '.') != 3)
            return false;
        
        vector<string> parts = split(IP, '.');
        if (parts.size() != 4) {
            return false;
        }
        
        for (string part : parts) {
            if(part.empty() || part.size() > 3 || part.size() > 1 && part[0] == '0')
                return false;
            
            for (char c : part) {
                if (!isdigit(c)) {
                    return false;
                }
            }
            if (stoi(part) > 255) {
                return false;
            }
        }
        return true;
    }
    
    bool is_ipv6(string IP) {
        if (count(IP.begin(), IP.end(), ':') != 7) {
            return false;
        }
        vector<string> parts = split(IP, ':');
        if (parts.size() != 8) {
            return false;
        }
        for (string part : parts) {
            if (part.empty() || part.size() > 4) {
                return false;
            }
            for (char c : part) {
                if (!isdigit(c) && (!isalpha(c) || toupper(c) > 'F')) {
                    return false;
                }
            }
        }
        return true;
    }
    
    vector<string> split(string s, char c) {
        vector<string> parts;
        string part;
        istringstream in(s);
        while (getline(in, part, c)) {
            parts.push_back(part);
        }
        return parts;
    }
};