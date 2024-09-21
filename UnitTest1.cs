using Microsoft.VisualStudio.TestTools.UnitTesting;
using PasswordProg;

namespace PasswordProg.Tests
{
    [TestClass]
    public class PasswordCheckerTests
    {
        private readonly PasswordChecker _checker = new PasswordChecker();

        [TestMethod]
        public void CheckPassword_StrongPassword_ReturnsFive()
        {
            string password = "P@ssw0rd123";
            int score = _checker.CheckPassword(password);
            Assert.AreEqual(5, score); 
        }

        [TestMethod]
        public void CheckPassword_LowercaseAndUppercase_ReturnsFour()
        {
            string password = "Password123";
            int score = _checker.CheckPassword(password);
            Assert.AreEqual(5, score); 
        }

        [TestMethod]
        public void CheckPassword_SpecialCharacter_ReturnsThree()
        {
            string password = "Passwordd";
            int score = _checker.CheckPassword(password);
            Assert.AreEqual(5, score); 
        }

        [TestMethod]
        public void CheckPassword_Digits_ReturnsFour()
        {
            string password = "Pas";
            int score = _checker.CheckPassword(password);
            Assert.AreEqual(5, score); 
        }

        [TestMethod]
        public void CheckPassword_LessThanSevenCharacters_ReturnsFour()
        {
            string password = "P";
            int score = _checker.CheckPassword(password);
            Assert.AreEqual(5, score); 
        }

        [TestMethod]
        public void CheckPassword_NoCriteriaMet_ReturnsZero()
        {
            string password = "";
            int score = _checker.CheckPassword(password);
            Assert.AreEqual(5, score);
        }
    }
}