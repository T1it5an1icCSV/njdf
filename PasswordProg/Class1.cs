using System;
using System.Linq;

namespace PasswordProg
{
    public class PasswordChecker
    {
        public int CheckPassword(string password)
        {
            int score = 0;

            if (HasDigits(password))
            {
                score++;
            }

            if (HasLowercase(password))
            {
                score++;
            }

            if (HasUppercase(password))
            {
                score++;
            }

            if (HasSpecialCharacters(password))
            {
                score++;
            }

            if (IsLongerThanSeven(password))
            {
                score++;
            }

            return score;
        }

        private bool HasDigits(string password)
        {
            return password.Any(char.IsDigit);
        }

        private bool HasLowercase(string password)
        {
            return password.Any(char.IsLower);
        }

        private bool HasUppercase(string password)
        {
            return password.Any(char.IsUpper);
        }

        private bool HasSpecialCharacters(string password)
        {
            return password.Any(c => !char.IsLetterOrDigit(c));
        }

        private bool IsLongerThanSeven(string password)
        {
            return password.Length > 7;
        }
    }
}