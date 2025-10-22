# Arithmetic-Game-with-Leaderboards-and-Login
Timed math quiz game with user login/signup. Practice addition, subtraction, multiplication, division in 40s challenges. Tracks scores per operation, maintains leaderboard. Simple CLI with file-based accounts &amp; rankings.

Timed arithmetic practice program with user login/signup. Practice addition, subtraction, multiplication, and division in 40-second challenges. Tracks scores per operation and maintains a global leaderboard.
Features:

✅ User authentication (signup/login)
✅ 4 math operations with random questions
✅ 40-second timed challenges
✅ Per-operation score tracking
✅ Global leaderboard
✅ File-based persistent storage

🚀 How to Use
Compile & Run:
bashg++ main.cpp -o arithmetic_game
./arithmetic_game

Login Flow:
text1. Sign up → 2. Login → 3. Choose Operation → 4. Play (40s) → 5. View Leaderboard

Gameplay:
Solve as many equations as possible in 40 seconds
Get instant feedback (Correct/Incorrect)
Scores automatically saved to leaderboard


🎮 Sample Session
textWelcome to the Arithmetic Practice Program!
1.) Sign up    2.) Login    3.) Exit > 2

Input Username: josh
Input Password: 1234
Login Success!

1.) Addition    2.) Subtraction    3.) Multiplication    4.) Division    5.) Leaderboard
> 1

ITS ADDITION TIME!!
You have 40 seconds to solve every equation. GOOD LUCK!
7 + 12 = 19    THAT IS CORRECT!
...
Time's up! You got 28 correct answers.
📁 Files Created

Accounts.txt - User credentials
Leaderboard.txt - Scores by user/game

🏆 Leaderboard Example
textARITHMETIC PRACTICE LEADERBOARD
RANK    NAME        SCORE    GAME
Rank 1. josh        28       Addition
Rank 2. student     25       Multiplication

⚡ Quick Stats
Questions per game: Unlimited (40s timer)
Number ranges:

























OperationRangeAddition1-15 + 1-15Subtraction10-30 - 1-9Multiplication1-15 × 1-15DivisionExact (no remainder)


🔧 Tech Stack

Language: C++
Storage: File I/O (text files)
Randomization: srand(time(0))
Sorting: STL sort algorithm

📝 License
Educational project - Free to use/modify for learning purposes.
