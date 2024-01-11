#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

vector<int> getConcatenation(vector<int> nums)
{
    int n = nums.size();
    vector<int> doublevector(2 * n);
    for (int i = 0; i < n; i++)
    {
        doublevector[i] = nums[i];
        doublevector[i + n] = doublevector[i];
    }
    return doublevector;
}

int numIdenticalPairs(vector<int> nums)
{
    int numGoodPairs = 0, test = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i; j < nums.size(); j++)
        {
            if (nums[i] == nums[j] && i < j)
            {
                if (test == 0)
                {
                    cout << "\nThe good pairs: \n";
                    test++;
                }
                cout << "(" << i + 1 << "," << j + 1 << ")" << endl;
                numGoodPairs++;
            }
        }
    }
    cout << "\nNumber of good pairs: ";
    return numGoodPairs;
}

int finalValueAfterOperations(vector<string> operations)
{

    int outcome = 0;
    for (int i = 0; i < operations.size(); i++)
    {
        if (operations[i] == "++X" || operations[i] == "X++")
        {
            cout << " X is incremented by 1, X= " << outcome << " + 1 = ";
            outcome += 1;
            cout << outcome << endl;
        }
        else
        {
            cout << " X is decremented by 1, X= " << outcome << " - 1 = ";
            outcome -= 1;
            cout << outcome << endl;
        }
    }
    return outcome;
}

vector<int> shuffle(vector<int> nums, int n)
{

    vector<int> outcome;

    for (int i = 0; i < n; i++)
    {
        outcome.push_back(nums[i]);
        outcome.push_back(nums[i + n]);
    }

    return outcome;
}

int maximumWealth(vector<vector<int>> accounts)
{
    int sum = 0;
    int max = 0;
    int maxWealthCustomer = 0;
    for (int i = 0; i < accounts.size(); i++)
    {

        sum = 0;
        cout << "Customer " << i + 1 << " has a wealth of: ";
        for (int j = 0; j < accounts[i].size(); j++)
        {
            sum += accounts[i][j];
            if (j == accounts[i].size() - 1)
            {
                cout << accounts[i][j] << " = ";
            }
            else
            {
                cout << accounts[i][j];
                if (accounts[i][j + 1] > 0)
                {
                    cout << "+";
                }
            }
        }
        if (i == 0)
        {
            max = sum;
            maxWealthCustomer = i + 1;
        }
        if (sum > max)
        {
            max = sum;
            maxWealthCustomer = i + 1;
        }
        cout << sum << endl;
    }
    cout << "\nCostumer " << maxWealthCustomer << " is the richest with a wealth of: ";
    return max;
}

bool arrayStringsAreEqual(vector<string> word1, vector<string> word2)
{
    string firstVectorString = {}, secondVectorString = {};
    cout << " \nWord1 represents string ";
    for (int i = 0; i < word1.size(); i++)
    {
        firstVectorString += word1[i];
        if (i == word1.size() - 1)
        {
            cout << "\"" << word1[i] << "\"->";
        }
        else
        {
            cout << "\"" << word1[i] << "\"+";
        }
    }
    cout << "\"" << firstVectorString << "\"." << endl;
    cout << " \nWord2 represents string ";

    for (int i = 0; i < word2.size(); i++)
    {
        secondVectorString += word2[i];
        if (i == word2.size() - 1)
        {
            cout << "\"" << word2[i] << "\"->";
        }
        else
        {
            cout << "\"" << word2[i] << "\"+";
        }
    }
    cout << "\"" << secondVectorString << "\"" << endl;
    cout << "\nIs the first string the same as the second string?\n";

    return (firstVectorString == secondVectorString);
}

vector<int> findWordsContaining(vector<string> words, char theLetterToFind)
{

    vector<int> outcome;

    int test = 0;

    for (int i = 0; i < words.size(); i++)
    {

        for (int j = 0; j < words[i].size(); j++)
        {

            if (words[i].at(j) == theLetterToFind)
            {
                if (test == 0)
                {
                    cout << "\"" << theLetterToFind << "\" occurs in: ";
                    cout << "\"" << words[i] << "\"";
                    test++;
                }
                else if (i == words.size() - 1 && words.size() - test == 1)
                {
                    cout << ",\"" << words[i] << "\"." << endl;
                    test++;
                }
                else
                {
                    cout << ",\"" << words[i] << "\"";
                    test++;
                }

                outcome.push_back(i);
                break;
            }
        }
    }
    if (test == 0)
    {
        cout << "\"" << theLetterToFind << "\" doesnt occur in any of the given words. ";
    }
    return outcome;
}

string defangIPaddress(string address)
{
    string outcome;
    string parting = "[.]";
    for (int i = 0; i < address.size(); i++)
    {
        if (address.at(i) != '.')
        {
            outcome += address.at(i);
        }
        else
        {
            outcome += parting;
        }
    }
    return outcome;
}

int numJewelsInStones(string jewels, string stones)
{
    int numJewelsInStones = 0;
    for (int i = 0; i < jewels.size(); i++)
    {
        for (int j = 0; j < stones.size(); j++)
        {
            if (stones.at(j) == jewels.at(i))
            {
                if (numJewelsInStones == 0)
                {
                    cout << "\nThe jewels in your stones are: " << stones.at(j);
                }
                else if (i == jewels.size() - 1)
                {
                    cout << "," << stones.at(j) << endl;
                }
                else
                {
                    cout << "," << stones.at(j);
                }

                numJewelsInStones++;
            }
        }
    }
    cout << "\nThe total number of jewels in your stones is: ";
    return numJewelsInStones;
}

vector<string> sortPeople(vector<string> names, vector<int> heights)
{
    vector<string> tempName(1);
    vector<int> tempHeight(1);

    for (int i = 0; i < names.size(); i++)
    {
        for (int j = i + 1; j < names.size(); j++)
        {
            if (heights.at(i) < heights.at(j))
            {
                tempName.at(0) = names.at(i);
                names.at(i) = names.at(j);
                names.at(j) = tempName.at(0);

                tempHeight.at(0) = heights.at(i);
                heights.at(i) = heights.at(j);
                heights.at(j) = tempHeight.at(0);
            }
        }
    }
    cout << "\nThe sorted list of heights ranging from highest to lowest: " << endl;

    for (int i = 0; i < names.size(); i++)
    {

        cout << i + 1 << "." << names.at(i) << " at " << heights.at(i) << " cm." << endl;
    }
    return names;
}

int addTwoIntegers(int num1, int num2)
{
    return num1 + num2;
}

int maximum69Number(int num)
{
    int testForChange = 0;
    string numString = to_string(num);
    for (int i = 0; i < numString.size(); i++)
    {
        if (numString.at(i) == '6')
        {
            numString.at(i) = '9';

            testForChange++;
        }
        if (testForChange == 0)
        {
            cout << "\nThe number you typed is better without changes: " << endl;
        }
        else
        {
            cout << "\nThe maximum number after one change is: " << endl;
        }
        return num = stoi(numString);
    }
}

int fib(int n)
{
    if (n == 0)
    {
        return n;
    }
    else if (n == 1)
    {
        return n;
    }
    else
    {
        n = fib(n - 1) + fib(n - 2);
        return n;
    }
}

int commonFactors(int a, int b)
{
    int biggestNum, numCommmonFactors = 0;
    (a > b) ? (biggestNum = a / 2.0) : (biggestNum = b / 2.0);
    if (a == b)
    {
        numCommmonFactors++;
    }
    for (int i = 1; i <= biggestNum; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            if (numCommmonFactors == 0)
            {
                cout << "\nThe common factors of " << a << " and " << b << " are " << i;
            }
            else
            {
                cout << ", " << i;
            }
            numCommmonFactors++;
        }
    }

    cout << "\nThe total of common factors is: ";
    return numCommmonFactors;
}

string intToRoman(int num)
{
    string numInRoman;

    vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> valuesInRoman = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    for (int i = 0; i < values.size(); i++)
    {
        while (num >= values[i])
        {
            numInRoman += valuesInRoman[i];
            num -= values[i];
        }
    }

    return numInRoman;
}

vector<vector<int>> transpose(vector<vector<int>> matrix)
{

    vector<vector<int>> outcome(matrix[0].size(), vector<int>(matrix.size(), 0));
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {

            outcome[j][i] = matrix[i][j];
        }
    }

    return outcome;
}

int diagonalSum(vector<vector<int>> matrix)
{
    int sum = 0, test = 0;
    int orderOfMatrix = matrix.size();
    for (int i = 0; i < orderOfMatrix; i++)
    {
        for (int j = 0; j < orderOfMatrix; j++)
        {
            if (i == j || i + j == orderOfMatrix - 1)
            {
                if (test == 0)
                {
                    cout << "Diagonals sum: " << matrix[i][j];
                    test++;
                }
                else if (i == orderOfMatrix - 1 && j == orderOfMatrix - 1)
                {
                    if (matrix[i][j] >= 0)
                    {
                        cout << " + " << matrix[i][j] << " = ";
                    }
                    else
                    {
                        cout << " - " << matrix[i][j] * -1 << " = ";
                    }
                }
                else
                {
                    if (matrix[i][j] >= 0)
                    {
                        cout << " + " << matrix[i][j];
                    }
                    else
                    {
                        cout << " - " << matrix[i][j] * -1;
                    }
                }

                sum += matrix[i][j];
            }
        }
    }
    return sum;
}

bool checkXMatrix(vector<vector<int>> grid)
{

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid.size(); j++)
        {

            if ((i == j || i + j == (grid.size() - 1)))
            {
                if (grid[i][j] == 0)
                {
                    return false;
                }
            }
            else if (grid[i][j] != 0)
            {
                return false;
            }
        }
    }

    return true;
}

int diagonalPrime(vector<vector<int>> nums)
{
    int orderOfMatrix = nums.size();
    int maxPrime = 0;

    for (int i = 0; i < orderOfMatrix; i++)
    {
        for (int j = 0; j < orderOfMatrix; j++)
        {
            if (i == j || i + j == orderOfMatrix - 1)
            {
                int num = nums[i][j];
                int k = 2;
                if (num != 1)
                {

                    while (k <= sqrt(num))
                    {
                        if (num % k == 0)
                        {
                            break;
                        }
                        k++;
                    }

                    if (k > sqrt(num) && maxPrime < num)
                    {
                        maxPrime = num;
                    }
                }
            }
        }
    }

    return maxPrime;
}

int countNegatives(vector<vector<int>> grid)
{
    vector<int> negativeNumbers{};
    int numNegatives = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {

            if (grid[i][j] < 0)
            {
                negativeNumbers.push_back(grid[i][j]);
                numNegatives++;
            }
        }
    }
    if (negativeNumbers.size() == 0)
    {
        cout << "There is no negative numbers\n therefore the total of negative numbers is : ";
    }
    else
    {

        for (int i = 0; i < negativeNumbers.size(); i++)
        {
            if (negativeNumbers.size() == 1)
            {
                cout << "The only negative number is " << negativeNumbers[i] << " \ntherefore the total of negative numbers is: ";
                return numNegatives;
            }

            if (i == 0)
            {
                cout << "The negative numbers are: ";
                cout << negativeNumbers[i];
            }
            else if (i == negativeNumbers.size() - 1)
            {
                cout << ", " << negativeNumbers[i] << "."
                     << "\nThe total of negative numbers is: ";
            }
            else
            {
                cout << ", " << negativeNumbers[i];
            }
        }
    }
    return numNegatives;
}

int main()
{

    int numOfFunction;

    cout << "A simple program including 20 functions."
         << endl;
restart:
    cout << "\nList of functions and their corresponding number:" << endl;
    cout << " 1. Concatenation of Array." << endl;
    cout << " 2. Number of Good Pairs." << endl;
    cout << " 3. Final Value of Variable After Performing Operations." << endl;
    cout << " 4. Shuffle the Array." << endl;
    cout << " 5. Richest Customer Wealth." << endl;
    cout << " 6. Check If Two String Arrays are Equivalent." << endl;
    cout << " 7. Find Words Containing Character." << endl;
    cout << " 8. Defanging an IP Address." << endl;
    cout << " 9. Jewels and Stones." << endl;
    cout << "10. Sort the People." << endl;
    cout << "11. Add Two Integers." << endl;
    cout << "12. Maximum 69 Number." << endl;
    cout << "13. Fibonacci Number." << endl;
    cout << "14. Number of Common Factors." << endl;
    cout << "15. Integer to Roman." << endl;
    cout << "16. Transpose Matrix." << endl;
    cout << "17. Matrix Diagonal Sum." << endl;
    cout << "18. Check if Matrix Is X-Matrix." << endl;
    cout << "19. Prime In Diagonal." << endl;
    cout << "20. Count Negative Numbers in a Sorted Matrix.\n\n"
         << endl;

    cout << "To continue using the program type one of the corresponding numbers of a function : " << endl;
    cin >> numOfFunction;

    switch (numOfFunction)
    {

    case (1):
    {

        int length;

        cout << "\n\n 1. Concatenation of Array." << endl;
        cout << "Given an array with a identified length, the program creates an array with twice the length with the predisposed elements doubled." << endl
             << endl;
        cout << "Write the desired length of the array: " << endl;

        cin >> length;

        vector<int> nums(length);

        cout << "\nWrite the elements of the array." << endl;

        for (int i = 0; i < length; i++)
        {
            cout << "Element " << i + 1 << ": ";
            cin >> nums.at(i);
        }

        for (int i = 0; i < length; i++)
        {
            if (i == 0)
            {
                cout << "\nThe entered array: [";
                cout << nums[i] << ",";
            }
            else if (i == length - 1)
            {
                cout << nums[i] << "]." << endl;
            }
            else
            {
                cout << nums[i] << ",";
            }
        }

        vector<int> rez = getConcatenation(nums);

        cout << "\nThe doubled array: [ ";

        for (int i = 0; i < rez.size(); i++)
        {

            if (i == 2 * length - 1)
            {
                cout << rez[i] << " ]." << endl;
            }
            else
            {
                cout << rez[i] << ", ";
            }
        }
        goto restartDefault;
    }

    case (2):
    {

        int length;

        cout << "\n\n 2. Number of Good Pairs." << endl;
        cout << "Given an array with a identified length, the program returns the number of good pairs.\nA pair is called good when the numbers are equal." << endl
             << endl;
        cout << "Write the desired length of the array: " << endl;

        cin >> length;

        vector<int> nums(length);

        cout << "\nWrite the elements of the array." << endl;

        for (int i = 0; i < length; i++)
        {
            cout << "Element " << i + 1 << ": ";
            cin >> nums.at(i);
        }

        for (int i = 0; i < length; i++)
        {
            if (i == 0)
            {
                cout << "\nThe entered array: [";
                cout << nums[i] << ",";
            }
            else if (i == length - 1)
            {
                cout << nums[i] << "]." << endl;
            }
            else
            {
                cout << nums[i] << ",";
            }
        }
        cout << numIdenticalPairs(nums) << endl;

        goto restartDefault;
    }

    case (3):
    {

        int length;

        cout << "\n\n 3. Final Value of Variable After Performing Operations." << endl
             << endl;
        cout << "There is a programming language with only four operations and one variable X:\n ++X and X++ increments the value of the variable X by 1. \n--X and X-- decrements the value of the variable X by 1. " << endl
             << endl;

        cout << "Write the desired number of operations: " << endl;

        cin >> length;

        vector<string> operations(length);

        cout << "\nWrite the desired operations." << endl;
        cout << "(++X,X++,--X,X--)\n";

        for (int i = 0; i < length; i++)
        {
        wrongInput:
            cout << "\nElement " << i + 1 << ": ";

            cin >> operations.at(i);
            if (operations.at(i) == "++X" || operations.at(i) == "X++" || operations.at(i) == "--X" || operations.at(i) == "X--")
            {
                continue;
            }
            else
            {
                cout << "Wrong input" << endl;
                cout << "Allowed input: ++X , X++ , --X , X-- \n";

                goto wrongInput;
            }
        }

        for (int i = 0; i < length; i++)
        {
            if (i == 0)
            {
                cout << "\nThe entered array: [";
                cout << operations[i] << ",";
            }
            else if (i == length - 1)
            {
                cout << operations[i] << "]." << endl;
            }
            else
            {
                cout << operations[i] << ",";
            }
        }

        int rez = finalValueAfterOperations(operations);
        cout << "\nFinal value after operations: " << rez;

        goto restartDefault;
    }
    case (4):
    {

        int n;

        cout << "\n\n 4. Shuffle the Array. \n";
        cout << "\nGiven the array, which has a length that is twice the given midpoint element number.\nThe program returns the array [x1,x2,...,xn,y1,y2,...,yn] in the form of [x1,y1,x2,y2,...,xn,yn]." << endl;
        cout << "Write the desired midpoint element number of array: " << endl;
        cin >> n;
        int length = n * 2;

        cout << "The vectors length is twice the number of the midpoint: " << length;

        cout << "\n\nWrite the elements of the array." << endl;

        vector<int> nums(length);

        for (int i = 0; i < nums.size(); i++)
        {
            cout << "Element " << i + 1 << ": ";
            cin >> nums.at(i);
        }
        cout << endl;

        vector<int> outcome = shuffle(nums, n);

        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0)
            {
                cout << "The entered array: [";
                cout << nums[i] << ",";
            }
            else if (i == nums.size() - 1)
            {
                cout << nums[i] << "]." << endl;
            }
            else
            {
                cout << nums[i] << ",";
            }
        }

        for (int i = 0; i < outcome.size(); i++)
        {
            if (i == 0)
            {
                cout << "\nThe shuffled array: [";
                cout << outcome[i] << ",";
            }
            else if (i == outcome.size() - 1)
            {
                cout << outcome[i] << "]." << endl;
            }
            else
            {
                cout << outcome[i] << ",";
            }
        }

        goto restartDefault;
    }
    case (5):
    {

        int numCustomers, numBanks;

        cout << "\n\n 5. Richest Customer Wealth." << endl
             << endl;
        cout << "Given the matrix where there is i-customers and j-banks.\nThe program returns the wealthiest customer calculating the amount of money on all of their banks." << endl
             << endl;
        cout << " Write the desired number of costumers: " << endl;

        cin >> numCustomers;

        cout << "Write the number of banks accounts: " << endl;

        cin >> numBanks;

        vector<vector<int>> accounts(numCustomers, vector<int>(numBanks, 0));

        for (int i = 0; i < numCustomers; i++)
        {
            for (int j = 0; j < numBanks; j++)
            {
                cout << "Write the wealth of customer " << i + 1 << " for bank number " << j + 1 << " : ";
                cin >> accounts[i][j];
            }
        }
        cout << "\nThe entered matrix containing data for customers: \n";
        for (int i = 0; i < numCustomers; i++)
        {
            for (int j = 0; j < numBanks; j++)
            {
                if (j == 0)
                {

                    cout << "Costumer " << i + 1 << " bank accounts = [" << accounts[i][j];
                }
                else if (j == accounts[i].size() - 1)
                {
                    cout << accounts[i][j] << "]." << endl;
                }

                else
                {
                    cout << "," << accounts[i][j] << ",";
                }
                if (j == 0 && j == accounts[i].size() - 1)
                {
                    cout << "]." << endl;
                }
            }
        }
        cout << endl;
        cout << maximumWealth(accounts);

        goto restartDefault;
    }

    case (6):
    {

        int lengthFirstArray, lengthSecondArray;

        cout << "\n\n 6. Check If Two String Arrays are Equivalent.\n"
             << endl;

        cout << "Given two string arrays, the program checks if the two arrays represent the same string.\n"
             << endl;

        cout
            << "Write the desired length of the first array: " << endl;

        cin >> lengthFirstArray;

        cout << "\nWrite the desired length of the second array: " << endl;

        cin >> lengthSecondArray;

        vector<string> word1(lengthFirstArray);
        vector<string> word2(lengthSecondArray);

        cout << "\nWrite the elements of the first string array: " << endl;

        for (int i = 0; i < lengthFirstArray; i++)
        {
            cout << "Word " << i + 1 << ": ";
            cin >> word1.at(i);
        }
        cout << "\nWrite the elements of the second string array: " << endl;

        for (int i = 0; i < lengthSecondArray; i++)
        {
            cout << "Word " << i + 1 << ": ";
            cin >> word2.at(i);
        }

        int testForBoolArrayString = arrayStringsAreEqual(word1, word2);

        if (testForBoolArrayString == 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }

        goto restartDefault;
    }
    case (7):
    {

        cout << "\n\n 7. Find Words Containing Character." << endl;

        cout << "Given an array of string and a character,\nthe program returns the words that contain the requested character and their position on the original array." << endl
             << endl;

        int length;
        cout << "Write the desired amount of words you want to check: ";
        cin >> length;
        char theLetterToFind;
        cout << "\nWrite the letter you are checking for: ";
        cin >> theLetterToFind;

        vector<string> words(length);
        cout << "\nWrite the desired words: \n";
        for (int i = 0; i < words.size(); i++)
        {
            cout << "Word " << i + 1 << ": ";
            cin >> words.at(i);
        }

        for (int i = 0; i < words.size(); i++)
        {
            if (i == 0)
            {
                cout << "\nThe entered words: \n";
                cout << i + 1 << ".\"" << words[i] << "\".\n";
            }
            else
            {
                cout << i + 1 << ".\"" << words[i] << "\".\n";
            }
        }
        cout << endl;

        vector<int> rez = findWordsContaining(words, theLetterToFind);
        int test = 0;
        if (rez.size() != 0)
        {
            cout << " in positions ";
            for (int i = 0; i < rez.size(); i++)
            {
                if (test == 0)
                {
                    cout << rez[i] + 1;
                    test++;
                }
                else if (i == rez.size() - 1 && rez.size() - test == 1)
                {
                    cout << "," << rez[i] + 1 << ".";
                    test++;
                }
                else
                {
                    cout << "," << rez[i] + 1;
                    test++;
                }
            }
        }

        goto restartDefault;
    }

    case (8):
    {

        cout << "\n\n 8. Defanging an IP Address." << endl;
        cout << "Given a valid (IPv4) IP address (Ex: 255.255.255.1.1), the program returns a defanged version of that IP address." << endl;

        string address;

        cout << "\nWrite a (IPv4) IP address: ";

        cin >> address;

        cout << "\nThe given IP address: " << address << endl;

        cout << "\nThe defanged IP address: " << defangIPaddress(address) << endl;

        goto restartDefault;
    }
    case (9):
    {

        cout << "\n\n 9. Jewels and Stones." << endl;

        cout << "\nGiven two strings:\n\"jewels\" representing the stones that are jewels,\n\"stones\" representing the stones you have.\nThe program outputs the total of jewels you have.\n\nWarning each character is considered a differnet jewel." << endl;
        string jewels, stones;
        cout << "\nWrite characters representing the types of stones that are jewels:\n";
        cin >> jewels;
        cout << "Write characters representing the stones you have: \n";
        cin >> stones;

        cout << numJewelsInStones(jewels, stones);
        cout << endl;
        goto restartDefault;
    }
    case (10):
    {

        cout << "\n\n10. Sort the People." << endl;

        cout << "\nGiven an array of people and their corresponding heights (in cm).\nThe program returns the names sorted in a descending order by the people's heights."
             << endl
             << endl;

        int numOfPeople;

        cout << "Write the number of people you want to compare heights with: " << endl;
        cin >> numOfPeople;

        vector<string> names(numOfPeople);
        vector<int> heights(numOfPeople);

        for (int i = 0; i < numOfPeople; i++)
        {

            cout << "Write the name of person number " << i + 1 << ": " << endl;
            cin >> names.at(i);

        wrongInputHeight:
            cout << "Write the height of person number " << i + 1 << ": " << endl;

            cin >> heights.at(i);
            if (heights.at(i) < 0)
            {
                cout << "Negative heights do not exist.\n";
                goto wrongInputHeight;
            }

            cout << endl;
        }

        cout << "The given list of people and their heights: " << endl;

        for (int i = 0; i < names.size(); i++)
        {

            cout << i + 1 << "." << names.at(i) << " at " << heights.at(i) << " cm." << endl;
        }

        vector<string> listedNames = sortPeople(names, heights);

        goto restartDefault;
    }
    case (11):
    {

        cout << "\n\n11. Add Two Integers." << endl;

        cout << "Given two integers, the program returns the sum of them." << endl
             << endl;

        int num1, num2;

        cout << "Write the first number: \n";
        cin >> num1;

        cout << "Write the second number: \n";
        cin >> num2;

        cout << num1;
        if (num2 < 0)
        {
            cout << " - " << num2 * -1 << " = " << addTwoIntegers(num1, num2) << endl;
        }
        else
        {
            cout << " + " << num2 << " = " << addTwoIntegers(num1, num2) << endl;
        }

        goto restartDefault;
    }
    case (12):
    {

        cout << "\n\n12. Maximum 69 Number." << endl
             << endl;

        cout << "Given a positive integer consisting only of digits 6 and 9.\nThe program returns the maximum number you can get by changing at most one digit where 6 becomes 9." << endl;

        int num;

    wrongInput69:
        cout << "\nWrite your desired number: \n";

        cin >> num;

        string numString = to_string(num);

        for (int i = 0; i < numString.size(); i++)
        {
            if (numString.at(i) != '9')
            {
                if (numString.at(i) != '6')
                {
                    cout << "Wrong input.\nThe number must be positive and only contain numbers 6 and 9." << endl;
                    goto wrongInput69;
                }
            }
        }

        cout << maximum69Number(num) << endl;
        goto restartDefault;
    }

    case (13):
    {

        cout << "\n\n13. Fibonacci Number." << endl
             << endl;
        cout << "Given a number, the program calculates the n-th number of the Fibonacci sequence.\n";

        int n;
    wrongInputFibonacci:
        cout << "\nWrite the desired number: \n";
        cin >> n;

        if (n <= 0)
        {
            cout << "\nPlease write a positive number.";
            goto wrongInputFibonacci;
        }

        int a = 1, b = 1;
        cout << "\nFibonacci sequence up to the " << n
             << "-th number is: \n\n";

        for (int i = 0; i < n; i++)
        {
            cout << a << " ";

            int next = a + b;
            a = b;
            b = next;
        }
        cout << "\n\nThe value of the " << n << "-th number is: " << fib(n) << endl;

        goto restartDefault;
    }

    case (14):
    {

        cout << "\n\n14. Number of Common Factors." << endl
             << endl;

        cout << "Given two positive numbers,\nthe program returns the number of common factors." << endl
             << endl;

        int a, b;

    wrongImputCommon1:
        cout << "Write the first number: \n";
        cin >> a;
        if (a <= 0)
        {
            cout << "\nPlease write a positive number.\n";
            goto wrongImputCommon1;
        }

    wrongImputCommon2:
        cout << "\nWrite the second number: \n";
        cin >> b;
        if (b <= 0)
        {
            cout << "Please write a positive number.\n";
            goto wrongImputCommon2;
        }

        cout << commonFactors(a, b);

        goto restartDefault;
    }

    case (15):
    {

        cout << "\n\n15. Integer to Roman." << endl;

        cout << "\nGiven a number, the program converts it to a roman numeral." << endl
             << endl;

        int num;
    wrongInputIntToRoman:
        cout << "Write the number you want to convert to roman: \n";
        cin >> num;

        if (num <= 0)
        {
            cout << "PLease write a positive number" << endl
                 << endl;
            goto wrongInputIntToRoman;
        }

        cout << "\nThe number " << num << " in roman is: " << intToRoman(num) << endl;

        goto restartDefault;
    }

    case (16):
    {

        cout << "\n\n16. Transpose Matrix." << endl;

        cout << "\nGiven a matrix, the program returns the transpose of the matrix.\n";

        int n, m;

        cout << "\nWrite the number of rows: \n";
        cin >> n;

        cout << "Write the number of columns: \n";
        cin >> m;
        cout << endl;
        vector<vector<int>> matrix(n, vector<int>(m, 0));

        vector<vector<int>> transposedMatrix(m, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << "Element[" << i + 1 << "][" << j + 1 << "]: ";
                cin >> matrix[i][j];
            }
        }

        cout << "\nThe given matrix:\n";

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << setw(6) << matrix[i][j];
            }
            cout << endl;
        }
        cout << endl;

        transposedMatrix = transpose(matrix);

        cout << "The transposed matrix:\n";

        for (int i = 0; i < transposedMatrix.size(); i++)
        {
            for (int j = 0; j < transposedMatrix[0].size(); j++)
            {
                cout << setw(6) << transposedMatrix[i][j];
            }
            cout << endl;
        }

        goto restartDefault;
    }

    case (17):
    {

        cout << "\n\n17. Matrix Diagonal Sum." << endl;

        cout << "\nGiven a square matrix,\nthe program returns the sum of the matix diagonals.\n"
             << endl;

        int n;

        cout << "Write the order of the matrix: \n";
        cin >> n;

        vector<vector<int>> matrix(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << "Element[" << i + 1 << "][" << j + 1 << "]: ";
                cin >> matrix[i][j];
            }
        }

        cout << "\nThe given matrix:\n";

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << setw(3) << matrix[i][j];
            }
            cout << endl;
        }
        cout << endl;

        cout << diagonalSum(matrix) << endl;

        goto restartDefault;
    }

    case (18):
    {

        cout << "\n\n18. Check if Matrix Is X-Matrix." << endl;

        cout << "\nGiven a square matrix,\nthe program checks if the matrix is a X-Matrix.\n\nThe order of the matrix must be bigger then 2. "
             << endl;
        int n;
    wrongInputXMatrix:
        cout << "Write the order of the matrix: \n";
        cin >> n;

        if (n < 3)
        {
            cout << "Wrong input" << endl;
            goto wrongInputXMatrix;
        }

        vector<vector<int>> grid(n, vector<int>(n, 0));
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << "Element[" << i + 1 << "][" << j + 1 << "]: ";
                cin >> grid[i][j];
            }
        }

        cout << "\nThe given matrix:\n";

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << setw(3) << grid[i][j];
            }
            cout << endl;
        }
        cout << endl;

        cout << "Is the given matrix a X-matrix? \n";

        int testForBool = checkXMatrix(grid);

        if (testForBool == 1)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }

        goto restartDefault;
    }

    case (19):
    {

        cout << "\n\n19. Prime In Diagonal." << endl;

        cout << "Given a matrix, the program returns the largest prime number that lies on at least one of the diagonals of the matrix." << endl
             << endl;

        int n;

        cout << "\nWrite the order of the matrix: \n";
        cin >> n;

        vector<vector<int>> nums(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << "Element[" << i + 1 << "][" << j + 1 << "]: ";
                cin >> nums[i][j];
            }
        }

        cout << "\nThe given matrix:\n";

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << setw(3) << nums[i][j];
            }
            cout << endl;
        }
        cout << endl;

        cout << "The largest prime in diagonals is: " << diagonalPrime(nums) << endl;

        goto restartDefault;
    }

    case (20):
    {

        cout << "\n\n20. Count Negative Numbers in a Sorted Matrix." << endl;

        cout << "\nGiven a matrix, the program returns the number of negative numbers." << endl;

        int n, m;

        cout << "\nWrite the number of rows: \n";
        cin >> n;

        cout << "Write the number of columns: \n";
        cin >> m;
        cout << endl;
        vector<vector<int>> grid(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << "Element[" << i + 1 << "][" << j + 1 << "]: ";
                cin >> grid[i][j];
            }
        }

        cout << "\nThe given matrix:\n";

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << setw(3) << grid[i][j];
            }
            cout << endl;
        }
        cout << endl;

        cout << countNegatives(grid) << endl;

        goto restartDefault;
    }
    default:
        cout << "The number you wrote doesnt correspond to any function." << endl;
    restartDefault:
        cout << "\nDo you want to relaunch the program('Y') or to end it('N')." << endl;

        char testDefault;
        cin >> testDefault;

        switch (testDefault)
        {
        case 'Y':
            goto restart;
        case 'N':
            return 0;
        default:
            cout << "Not a supported answer.\n";
            goto restartDefault;
        }
    }

    return 0;
}
