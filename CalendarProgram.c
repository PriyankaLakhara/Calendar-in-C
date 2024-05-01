#include <stdio.h>

// Function to check if a given day is a holiday for the specified month
int is_holiday(int day, int month) {
    if (month == 1 && day == 1) {
        return 1; // New Year's Day
    }
    if (month == 1 && day == 14) {
        return 2; // Makar Sankranti/Pongal
    }
    if (month == 1 && day == 26) {
        return 3; // Republic Day
    }
    if (month == 3 && day == 1) {
        return 4; // Maha Shivaratri
    }
    if (month == 3 && day == 8) {
        return 5; // Holi
    }
    if (month == 4 && day == 2) {
        return 6; // Good Friday
    }
    if (month == 6 && day == 5) {
        return 7; // Eid al-Fitr
    }
    if (month == 8 && day == 15) {
        return 8; // Independence Day
    }
    if (month == 8 && day == 22) {
        return 9; // Raksha Bandhan
    }
    if (month == 8 && day == 30) {
        return 10; // Janmashtami
    }
    if (month == 9 && day == 1) {
        return 11; // Navratri
    }
    if (month == 9 && day == 10) {
        return 12; // Ganesh Chaturthi
    }
    if (month == 10 && day == 2) {
        return 13; // Gandhi Jayanti
    }
    if (month == 10 && day == 15) {
        return 14; // Dussehra
    }
    if (month == 10 && day == 24) {
        return 15; // Diwali
    }
    if (month == 12 && day == 25) {
        return 16; // Christmas
    }
    return 0; // No holiday found
}

int main() {
    int year, month, daysInMonth, startingDay, dayOfWeek;

    // Input year and month
    printf("Enter year: ");
    scanf("%d", &year);
    printf("Enter month (1-12): ");
    scanf("%d", &month);

    // Calculate the number of days in the month
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            daysInMonth = 29; // Leap year
        } else {
            daysInMonth = 28; // Non-leap year
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        daysInMonth = 30; // April, June, September, November
    } else {
        daysInMonth = 31; // All other months
    }

    // Calculate the starting day of the month
    startingDay = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
    for (int i = 1; i < month; ++i) {
        if (i == 2) {
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                startingDay += 29; // Leap year
            } else {
                startingDay += 28; // Non-leap year
            }
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            startingDay += 30; // Months with 30 days
        } else {
            startingDay += 31; // Months with 31 days
        }
    }

    // Set dayOfWeek with 0 representing Sunday
    dayOfWeek = startingDay % 7;

    // Display the calendar
    printf("\n==============================\n");
    printf("           %d-%02d\n", year, month);
    printf("==============================\n");
    printf(" Sun Mon Tue Wed Thu Fri Sat\n");

    // Print spaces for the days before the starting day of the month
    for (int i = 0; i < dayOfWeek; ++i) {
        printf("    "); // Print spaces for days before the starting day
    }

    // Print the days of the month with color for Sundays and holidays
    for (int day = 1; day <= daysInMonth; ++day) {
        int holidayCode = is_holiday(day, month);

        // Color Sundays in red
        if ((day + dayOfWeek) % 7 == 1) {
            printf("\033[31m%4d\033[0m", day); // Red for Sundays
        } else if (holidayCode > 0) { // Green for holidays
            printf("\033[32m%4d\033[0m", day);
        } else {
            printf("%4d", day); // Normal day
        }

        if ((day + dayOfWeek) % 7 == 0) { // Start new line after every Saturday
            printf("\n");
        }
    }

    // List holidays specific to the selected month
    int hasHolidays = 0; // Indicator for holidays in this month
    printf("\nHolidays in %d-%02d:\n", year, month);

    for (int day = 1; day <= daysInMonth; ++day) {
        int holidayCode = is_holiday(day, month);
        if (holidayCode > 0) {
            hasHolidays = 1; // Indicate there is at least one holiday

            // Use switch-case or if-else to determine the holiday reason
            switch (holidayCode) {
                case 1:
                    printf("%d New Year's Day\n", day);
                    break;
                case 2:
                    printf("%d Makar Sankranti/Pongal\n", day);
                    break;
                case 3:
                    printf("%d Republic Day\n", day);
                    break;
                case 4:
                    printf("%d Maha Shivaratri\n", day);
                    break;
                case 5:
                    printf("%d Holi\n", day);
                    break;
                case 6:
                    printf("%d Good Friday\n", day);
                    break;
                case 7:
                    printf("%d Eid al-Fitr\n", day);
                    break;
                case 8:
                    printf("%d Independence Day\n", day);
                    break;
                case 9:
                    printf("%d Raksha Bandhan\n", day);
                    break;
                case 10:
                    printf("%d Janmashtami\n", day);
                    break;
                case 11:
                    printf("%d Navratri\n", day);
                    break;
                case 12:
                    printf("%d Ganesh Chaturthi\n", day);
                    break;
                case 13:
                    printf("%d Gandhi Jayanti\n", day);
                    break;
                case 14:
                    printf("%d Dussehra\n", day);
                    break;
                case 15:
                    printf("%d Diwali\n", day);
                    break;
                case 16:
                    printf("%d Christmas\n", day);
                    break;
            }
        }
    }

    if (hasHolidays == 0) { // If no holidays were found
        printf("No holidays in this month except Sundays\n");
    }

    printf("\n");
    return 0;
}
