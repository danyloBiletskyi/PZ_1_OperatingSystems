#include <iostream>
#include <cctype>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>

//task 1
void GetNumberSimplified();

//task 2.1
void CalculateFunction();
double f1(double z);
double f2(double z);
double f3(double z);
double f(double x);

//task 2.2
void PrintMonthsAndDaysAccordingToSeason(int season);

//task 3.1
int maxElementInASequence();
bool isAStringHasOnlyDigits(std::string stringForCheck);

void maxElementInASequenceWithDoWhile();
bool isAStringHasOnlyDigitsFor(const std::string& str);

//task 3.2
void PrintTableFunction();
int CalculateFunctionResult(double x);

//Actual solution


int main() {

	//---------------------TASK 1---------------------
	//GetNumberSimplified();


	//---------------------TASK 2.1-------------------
	//CalculateFunction();

	//---------------------TASK 2.2-------------------
	//std::cout << "Enter the number of season: \n1 - winter;\n2 - spring;\n3 - summer;\n4 - autumn;" << std::endl;
	//	int season;
	//	std::cin >> season;
	//	PrintMonthsAndDaysAccordingToSeason(season);
	
	//---------------------TASK 3.1-------------------
	// FOR LOOP + WHILE LOOP
	//int max = maxElementInASequence();
	//std::cout << "Max element is: " << max;

	//FOR LOOP + DO WHILE LOOP
	//void maxElementInASequenceWithDoWhile()

	//---------------------TASK 3.2-------------------
	//PrintTableFunction();

	return 0;
}


//------------------------------------------------------TASK 1------------------------------------------------------

void GetNumberSimplified() {
	double number;
	std::cout << "Input a number: ";
	std::cin >> number;

	std::cout << std::fixed << std::setprecision(2) << number << std::endl;
}

//------------------------------------------------------TASK 2.1----------------------------------------------------

void CalculateFunction() {
	const double c = 2.7;

	double z = cos(c);

	double result;
	if (z < 0) {
		result = f1(z);
	}
	else if (0 <= z && z <= 8) {
		result = f2(z);
	}
	else {
		result = f3(z);
	}

	double final_result = f(result);

	std::cout << "f(x): " << final_result << std::endl;
}



double f(double x) {
	return log(x) - exp(2 * x);
}

double f1(double z) {
	return pow(z, 2) + exp(z);
}

double f2(double z) {
	return pow(cos(z), 4) / pow(z, 3);
}

double f3(double z) {
	return tan(2 * z) + pow(z, 3);
}

//------------------------------------------------------TASK 2.2----------------------------------------------------

void PrintMonthsAndDaysAccordingToSeason(int season) {
	using namespace std;
	string months[12] = {"December", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November"};
	int days[12] = { 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30,  };
	if (season == 1) {
		cout << "Printing winter months: " << endl;
		for (int i = 0; i < 3; i++) {
			cout << months[i] << " has " << days[i] << " days" << endl;
		}
	}
	else if (season == 2) {
		cout << "Printing spring months: " << endl;
		for (int i = 3; i < 6; i++) {
			cout << months[i] << " has " << days[i] << " days" << endl;
		}
	}
	else if (season == 3) {
		cout << "Printing summer months: " << endl;
		for (int i = 6; i < 9; i++) {
			cout << months[i] << " has " << days[i] << " days" << endl;
		}
	}
	else if (season == 4) {
		cout << "Printing autumn months: " << endl;
		for (int i = 9; i < 12; i++) {
			cout << months[i] << " has " << days[i] << " days" << endl;
		}
	}
	else {
		cout << "Mistake, there is no such season" << endl;
	}
}

//------------------------------------------------------TASK 3.1----------------------------------------------------

// FOR AND WHILE LOOP SOLUTION

int maxElementInASequence() {
	using namespace std;

	int max = 0;
	std::cout << "Enter a number. If u want to quit - enter 'q' character" << std::endl;
	while (true) {
		string input;
		cin >> input;
		if (input == "q") {
			break;
		}
		else if (!isAStringHasOnlyDigits(input)) {
			std::cout << "Current element is not a digit. If you want to quit write 'q', otherwise please input integers" << std::endl;
			continue;
		}
		else {
			int input_ = stoi(input);
			if (max < input_) {
				max = input_;
			}
		}
	}
	return max;
}

bool isAStringHasOnlyDigits(std::string stringForCheck) {
	int length = stringForCheck.size();
	bool isDigit = true;
	for (int i = 0; i < length; i++) {
		if (!isdigit(stringForCheck[i])) {
			isDigit = false;
		}
	}
	return isDigit;
}

// FOR AND DO WHILE LOOP SOLUTION

void maxElementInASequenceWithDoWhile() {
	using namespace std;
	int max = 0;
	int currentDigit = 0;
	std::cout << "Enter a number, if you want to quit - press '=' on your keyboard " << std::endl;
	string input;

	do {
		cin >> input;
		if (isAStringHasOnlyDigitsFor(input)) {
			currentDigit = stoi(input);
			if (max >= currentDigit) {
				continue;
			}
			else {
				max = currentDigit;
			}
		}
	} while (input != "=");
	std::cout << "Max number: " << max << std::endl;
}

bool isAStringHasOnlyDigitsFor(const std::string& str) {
	for (char c : str) {
		if (!std::isdigit(c)) {
			return false;
		}
	}
	return true;
}

//------------------------------------------------------TASK 3.2----------------------------------------------------

void PrintTableFunction() {
	using namespace std;
	const int firstLastRowSize = 14;

	cout << "Argument value" << "|" << "Function value" << endl;
	for (double i = 0.5; i < 6; i += 0.3) {
		double functionValue = CalculateFunctionResult(i);
		stringstream stream;
		stream << fixed << setprecision(2) << functionValue;
		string functionValueInString = stream.str();
		string argumentValueInString = to_string(i);
		cout << argumentValueInString << string(firstLastRowSize - argumentValueInString.size(), ' ') << "|" << functionValueInString << string(firstLastRowSize - functionValueInString.size(), ' ') << endl;
	}
}

int CalculateFunctionResult(double x) {
	using namespace std;
	double result = x * cos(1 / x) + 2;
	return result;
}

