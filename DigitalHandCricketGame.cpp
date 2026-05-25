#include <iostream>
#include <cstdlib> // For rand()
#include <ctime>   // For time()
#include <thread>
#include <iomanip> // For formatting
#include <chrono>
using namespace std;

enum difficulty_level { easy, normal, hard };

void play_background_music(const std::string& music_file) ;
void exit_game() ;
void play_sound(const std::string& sound_file);
difficulty_level current_difficulty_level;
void difficulty();
void display_menu();
void waitForKeyPress();
int toss_rand();
void select_gametype(int& overs);
void toss(int& batORbowl);
void select_user_team(string user_team[11]);
void select_comp_team(string comp_team[11]);
void scoreboard(int i, string user_team[11], int balls, int wickets, int score, int totalscore, int target);
void instructions();
void copy(string x[11], string y[11]);
void player_turn();
void computer_turn();
void decide_winner();
void loading();
void display_innings_summary(const string team[], const int scores[]);

string pak_player_names[11] = { "Babar Azam", "Mohammad Rizwan", "Fakhar Zaman", "Iftikhar Ahmed", "Shadab Khan", "Imad Wasim", "Shaheen Afridi", "Haris Rauf", "Naseem Shah", "Mohammad Nawaz", "Usama Mir" };
string eng_player_names[11] = { "Jos Buttler", "Dawid Malan", "Alex Hales", "Moeen Ali", "Liam Livingstone", "Ben Stokes", "Sam Curran", "Chris Woakes", "Adil Rashid", "Mark Wood", "Chris Jordan" };
string aus_player_names[11] = { "Aaron Finch", "David Warner", "Steve Smith", "Glenn Maxwell", "Marcus Stoinis", "Mitchell Marsh", "Pat Cummins", "Mitchell Starc", "Adam Zampa", "Josh Hazlewood", "Matthew Wade" };
string ind_player_names[11] = { "Rohit Sharma", "Virat Kohli", "KL Rahul", "Suryakumar Yadav", "Rishabh Pant", "Hardik Pandya", "Ravindra Jadeja", "Jasprit Bumrah", "Bhuvneshwar Kumar", "Yuzvendra Chahal", "Mohammed Shami" };
string nz_player_names[11] = { "Kane Williamson", "Martin Guptill", "Devon Conway", "Glenn Phillips", "James Neesham", "Mitchell Santner", "Tim Southee", "Trent Boult", "Lockie Ferguson", "Ish Sodhi", "Tom Latham" };
string wi_player_names[11] = { "Kieron Pollard", "Chris Gayle", "Nicholas Pooran", "Shimron Hetmyer", "Andre Russell", "Jason Holder", "Dwayne Bravo", "Sunil Narine", "Sheldon Cottrell", "Oshane Thomas", "Evin Lewis" };
string afg_player_names[11] = { "Mohammad Nabi", "Rashid Khan", "Mujeeb Ur Rahman", "Hazratullah Zazai", "Rahmanullah Gurbaz", "Najibullah Zadran", "Gulbadin Naib", "Asghar Afghan", "Hamid Hassan", "Karim Janat", "Naveen-ul-Haq" };
string sa_player_names[11] = { "Quinton de Kock", "Temba Bavuma", "Aiden Markram", "Rassie van der Dussen", "David Miller", "Dwaine Pretorius", "Kagiso Rabada", "Anrich Nortje", "Tabraiz Shamsi", "Lungi Ngidi", "Heinrich Klaasen" };
string sri_player_names[11] = { "Kusal Perera", "Danushka Gunathilaka", "Avishka Fernando", "Dhananjaya de Silva", "Dasun Shanaka", "Wanindu Hasaranga", "Dushmantha Chameera", "Lahiru Kumara", "Nuwan Pradeep", "Kusal Mendis", "Isuru Udana" };
string ban_player_names[11] = { "Tamim Iqbal", "Shakib Al Hasan", "Mushfiqur Rahim", "Mahmudullah", "Soumya Sarkar", "Liton Das", "Mustafizur Rahman", "Taskin Ahmed", "Mehidy Hasan", "Mohammad Saifuddin", "Afif Hossain" };

const int max_score = 6;
int batORbowl;
int target = 0;  // Store the target score
bool user_won = false;  // Determine the winner
int overs;
int totalBalls;
int frequency[6]={0,0,0,0,0,0};
int total_weight;
int cumulative_weight;


int team1_scores[10];
int team2_scores[10];
string user_team[11];
string comp_team[11];

int main()
{
	
	srand(static_cast<unsigned>(time(0))); // Ensure randomness

	while (true) {
		display_menu();
		waitForKeyPress();
	}

	return 0;
}

void display_menu() {
	cout << "\n";
	system("clear");
	play_background_music("background_music.mp3");
	cout << "\033[1;32m━━━━━━━━━━━━━━━━━━━━━━━━━━━⋆⋅☆⋅⋆━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m\n";
	cout << "\033[1;7;33m               \033[0m\033[1;37m  🏏 HAND CRICKET 2024 🏏  \033[1;7;33m                  \033[0m\n";
	cout << "\033[1;32m━━━━━━━━━━━━━━━━━━━━━━━━━━━━⊱⋆⊰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m\n";
	cout << "\033[1;36m             🎉 READY TO SMASH THE FIELD? 🎉              \033[0m\n";
	cout << "\033[1;32m============================================================\033[0m\n";
	cout << "\033[1;36m  1. \033[1;33mPLAY \033[0m🏏 (Start your cricket adventure!)\n";
	cout << "\033[1;36m  2. \033[1;33mINSTRUCTIONS \033[0m📜 (Learn how to play!)\n";
	cout << "\033[1;36m  3. \033[1;33mEXIT \033[0m❌ (Leave the game)\n";
	cout << "\033[1;32m============================================================\033[0m\n";
	cout << "\033[1;37mChoose an option to begin: \033[0m";


	int choice;	
	cin >> choice;

	switch (choice) {
	case 1:
		select_gametype(overs);loading();
		
		difficulty();loading();
		
		totalBalls = overs * 6;
		select_user_team(user_team);loading();
		select_comp_team(comp_team);loading();
		toss(batORbowl);
		if (batORbowl == 1) {
			player_turn();
			loading();
			computer_turn();
		}
		else if (batORbowl == 2) {
			computer_turn();
			loading();
			player_turn();
		}
		decide_winner();
		break;
	case 2:
		instructions();
		break;
	case 3:
		cout << "Exiting... Goodbye! \n";
		exit_game();
	default:
		cout << "Invalid choice! Please select a valid option. \n";
	}

	// Ask to display the menu again or exit
	char endChoice;
	cout << "Do you want to display the menu again? (y/n): ";
	cin >> endChoice;
	if (endChoice == 'n' || endChoice == 'N') {
		cout << "\033[1;33mExiting... \033[1;31mGoodbye! \033[0m\n";
		exit_game();
	}
}

void select_gametype(int& overs)
{
	system("clear");

	cout << "\033[1;32m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m\n";
	cout << "\033[1;33m               SELECT GAME MODE               \033[0m\n";
	cout << "\033[1;32m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m\n\n";
	cout << "\033[1;36m  1. \033[1;33mBlitz \033[1;37m- \033[1;34mQuick 2 over match\033[0m\n";
	cout << "\033[1;36m  2. \033[1;33mT 5 \033[1;37m- \033[1;34m5 overs\033[0m\n";
	cout << "\033[1;36m  3. \033[1;33mSuper Over \033[1;37m- \033[1;34mOne over each\033[0m\n";
	cout << "\033[1;36m  4. \033[1;33mCustom \033[1;37m- \033[1;34mCreate your own match!\033[0m\n";
	cout << "\033[1;36m  5. \033[1;33mGo Back to Main Menu \033[0m\n\n";
	cout << "\033[1;32m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m\n";

	cout << "\033[1;37mSelect your choice: \033[0m";
	int choice;
	cin >> choice;

	switch (choice)
	{
	case 1:
		overs = 2; //blitz mode
		break;
	case 2:
		overs = 5; // 5 overs mode
		break;
	case 3:
		overs = 1; //super over mode
		break;
	case 4:
		system("clear");
		cout << "Overs: ";
		cin >> overs; //custom overs mode
		break;
	default:
		loading();
		display_menu();
	}
}

//TOSS FUNCTION
void toss(int& batORbowl) {
	system("clear");
	
	cout << "\033[1;34m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m\n";
	cout << "\033[1;33m     ⚡ Time for the toss! ⚡           \033[0m\n";
	cout << "\033[1;34m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m\n\n";

	cout << "\033[1;36m 1. \033[1;32mHeads\033[0m\n";
	cout << "\033[1;36m 2. \033[1;32mTails\033[0m\n";

	cout << "\033[1;37mOption: \033[0m";

	int head_tails;
	cin >> head_tails;

	bool toss = toss_rand();  //randomly generate 1 or 0 and decide on that basis
	if (toss) {
		// if user wins the toss: 
		cout << "\033[1;32m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m\n";
		cout << "\033[1;33m     🎉 You won the toss!! 🎉           \033[0m\n";
		cout << "\033[1;32m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m\n\n";

		// ask whether user wants t o bowl first o rbat first
		do {
			cout << "\033[1;36mWould you like to bat first or bowl first?\033[0m\n\n";
			cout << "\033[1;34m 1. \033[1;32mBat\033[0m\n";
			cout << "\033[1;34m 2. \033[1;32mBowl\033[0m\n";
			cout << "\033[1;37mSelect an option: \033[0m";

			cin >> batORbowl;
		} while (batORbowl != 1 && batORbowl != 2);
	} else {
		//if user loses the toss: 
		cout << "\033[1;31mOh no! \033[1;37mOpponent won the toss... \033[1;33mBetter luck next time! \033[0m\n";
		loading();
		bool comp_decide = toss_rand();
		batORbowl = comp_decide ? 1 : 2;		//randomly decide whether computer will bat first or bowl first
	}
	 system("killall afplay");
}

void computer_turn() {
	int difficulty_count;
	int player_score = 0;
	int wickets = 0, balls = 0, score = 0, total_score = 0, i = 0;
	bool out = false;

	switch (current_difficulty_level) {
		case easy:
			difficulty_count = 3; break;
		case normal:
			difficulty_count = 2; break;
		case hard:
			difficulty_count = 1; break;
		default:
			difficulty_count = 3; break;
	}

	cout << "\033[1;32mIt's your turn to bowl! \033[0m\n";
	loading();

	while (wickets != 10 && balls < totalBalls) {  // Limit according to overs selected
		scoreboard(i, user_team, balls, wickets, score, total_score, target); //display scoreboard at the start.
		out = false;
		do {
			cout << "\033[1;34m\nSelect your option (1-6): \033[0m";
			cin >> score;
		} while (score < 1 || score > max_score);

		balls++;  // Increment balls every turn

		int comp_guess;
		for (int j = 0; j < difficulty_count; j++) {
			comp_guess = rand() % 6 + 1;  // Random computer score (1-6)
			if (comp_guess == score) {
				out = true;
				break;
			}
		}

		cout << "Computer selected score: " << comp_guess << endl;

		if (out) {  // Case for OUT
			cout << (rand() % 2 == 0 ? "UP IN THE AIR.... AND TAKEN!! That's a brilliant catch under pressure!!!\n" : "GONE! He's bowled him out of nowhere!!!\n");
			cout << "\033[1;31mThe umpire signals \033[1;37m\"OUT\" \033[0m\033[1;31m! \033[0m\n";

			team2_scores[i] = player_score;  // Store the score of the current player
			wickets++;
			i++;  // Next player
			player_score = 0;  // Reset player score
			loading();  // Reset player score


		}
		
		 else {
			player_score += comp_guess;
			total_score += comp_guess;
			loading();
		}
		

		if (target > 0 && total_score > target) {
			user_won = false;
			break;
		}
	}

	cout << "\033[1;31m\nEND of INNINGS!! \033[0m\n";
	if (target == 0) {
		target = total_score + 1;
		cout << "TARGET is: " << target << " \n\n\n";
	
	} else {
		cout << "Computer's total score: " << total_score << " \n";
		cout<<"Your total score: " << target;
		user_won = total_score < target;
		
	}

	// Display the summary for each batter
	display_innings_summary(comp_team, team2_scores);
	cout<<"Loading...";
	loading();loading();loading();
}

void player_turn() {
	int player_score = 0;
	int wickets = 0, balls = 0, score = 0, total_score = 0, i = 0;
	int random_chance;
	int difficulty_count;
	difficulty_count = 1;
	int comp_guess;
	bool out = false;

	switch (current_difficulty_level) {
		case easy:
			difficulty_count = 1; break;
		case normal:
			difficulty_count = 2; break;
		case hard:
			difficulty_count = 3; break;
		default:
			difficulty_count = 1;
	}

	cout << "\033[1;32mIt's your turn to BAT! \033[0m\n";
	loading();

	while (wickets != 10 && balls < totalBalls) {  // Limit according to overs selected
		scoreboard(i, user_team, balls, wickets, score, total_score, target);

		do {
			cout << "\033[1;34m\nSelect your option (1-6): \033[0m";
			cin >> score;
		} while (score < 1 || score > 6);

		out = false;
		balls++;  // Increment balls every turn

		for (int j = 0; j < difficulty_count; j++) {
			comp_guess = rand() % 6 + 1;  // Random computer score (1-6)
			if (comp_guess == score) {
				out = true;
				break;
			}
		}

		if (out) {  // Case for OUT
			int randomChoice = rand() % 2;
			if (randomChoice == 0) {
				play_sound("commentary/bowled.mp3");
				cout << "GONE EXCELLENT LENGTH!\nUP IN THE AIR.... AND TAKEN!! That's a brilliant catch under pressure!!!\n";
			} else {
				play_sound("commentary/bowled.mp3");
				cout << "GONE! He's bowled him out of nowhere!!!\n";
			}

			cout << "\033[1;31mThe umpire signals \033[1;37m\"OUT\" \033[0m\033[1;31m! \033[0m\n";
			team1_scores[i] = player_score;  // Store the score of the current player
			wickets++;
			i++;  // Next player
			player_score = 0; // Reset player score
			loading(); 
		} 
		else {
			player_score += score;  // Accumulate the score for the current player
			total_score += score;  // Accumulate the total score for the team
			
			if (score == 6 && score != comp_guess) {
				cout << "THAT'S A MASSIVE HIT!!! SAILING OVER THE BOUNDARY... SIX runs!\n";
				loading();
				continue; // Continue so that it doesn't load twice
			}
			else if (score == 4 && score != comp_guess) {
				cout << "BEAUTIFULLY timed! That races to the boundary for FOUR!!!\n";
				loading();
				continue;
			}
			loading();
		}

		if (total_score >= target && target != 0) {
			break;  // Break if target is achieved
		}
	}

	cout << "\033[1;31m\nEND of INNINGS!! \033[0m\n";
	if (target == 0) {
		target = total_score + 1;
		cout << "TARGET is: " << target << " \n\n\n";
		loading();
	} else {
		cout << "Computer's total score: " << target << " \n";
		if (total_score < target && target > 0) {
			user_won = false;
		} else if (total_score > target && target > 0) {
			user_won = true;
		}
	}

	// Display the summary for each batter
	display_innings_summary(user_team, team1_scores);
	cout << "Loading...";
	loading(); loading(); loading();
}


void select_comp_team(string comp_team[11]) {
	int choose;
	do {
		system("clear");

		cout << "\033[1;32m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m\n";
		cout << "\033[1;33m          ⚡ Select Computer Team ⚡             \033[0m\n";
		cout << "\033[1;32m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m\n\n";

		cout << "\033[1;36m╔════╦══════════════════════════════════════════╗\033[0m\n";
		cout << "\033[1;36m║ No ║              Team Name                   ║\033[0m\n";
		cout << "\033[1;36m╠════╬══════════════════════════════════════════╣\033[0m\n";
		cout << "\033[1;36m║ 1  ║ Pakistan Cricket Team                    ║\033[0m\n";
		cout << "\033[1;36m║ 2  ║ England Cricket Team                     ║\033[0m\n";
		cout << "\033[1;36m║ 3  ║ Australian Cricket Team                  ║\033[0m\n";
		cout << "\033[1;36m║ 4  ║ Indian Cricket Team                      ║\033[0m\n";
		cout << "\033[1;36m║ 5  ║ New Zealand Cricket Team                 ║\033[0m\n";
		cout << "\033[1;36m║ 6  ║ West Indies Cricket Team                 ║\033[0m\n";
		cout << "\033[1;36m║ 7  ║ Afghanistan Cricket Team                 ║\033[0m\n";
		cout << "\033[1;36m║ 8  ║ South African Cricket Team               ║\033[0m\n";
		cout << "\033[1;36m║ 9  ║ Sri Lanka Cricket Team                   ║\033[0m\n";
		cout << "\033[1;36m║ 10 ║ Bangladesh Cricket Team                  ║\033[0m\n";
		cout << "\033[1;36m╚════╩══════════════════════════════════════════╝\033[0m\n";

		cout << "\033[1;37mSelect an option: \033[0m";

		cin >> choose;

		switch (choose) {
		case 1:
			copy(comp_team, pak_player_names);
			break;
		case 2:
			copy(comp_team, eng_player_names);
			break;
		case 3:
			copy(comp_team, aus_player_names);
			break;
		case 4:
			copy(comp_team, ind_player_names);
			break;
		case 5:
			copy(comp_team, nz_player_names);
			break;
		case 6:
			copy(comp_team, wi_player_names);
			break;
		case 7:
			copy(comp_team, afg_player_names);
			break;
		case 8:
			copy(comp_team, sa_player_names);
			break;
		case 9:
			copy(comp_team, sri_player_names);
			break;
		case 10:
			copy(comp_team, ban_player_names);
			break;
		default:
			cout << "Please select an appropriate option\n";
			break;
		}
	} while (choose > 10 || choose < 1);
}

void select_user_team(string user_team[11]) {
	int choose;
	do {
	system("clear");

		cout << "\033[1;32m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m\n";
		cout << "\033[1;33m              ⚡ Select Your Team ⚡              \033[0m\n";
		cout << "\033[1;32m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m\n\n";

		cout << "\033[1;36m╔════╦══════════════════════════════════════════╗\033[0m\n";
		cout << "\033[1;36m║ No ║              Team Name                   ║\033[0m\n";
		cout << "\033[1;36m╠════╬══════════════════════════════════════════╣\033[0m\n";
		cout << "\033[1;36m║ 1  ║ Pakistan Cricket Team                    ║\033[0m\n";
		cout << "\033[1;36m║ 2  ║ England Cricket Team                     ║\033[0m\n";
		cout << "\033[1;36m║ 3  ║ Australian Cricket Team                  ║\033[0m\n";
		cout << "\033[1;36m║ 4  ║ Indian Cricket Team                      ║\033[0m\n";
		cout << "\033[1;36m║ 5  ║ New Zealand Cricket Team                 ║\033[0m\n";
		cout << "\033[1;36m║ 6  ║ West Indies Cricket Team                 ║\033[0m\n";
		cout << "\033[1;36m║ 7  ║ Afghanistan Cricket Team                 ║\033[0m\n";
		cout << "\033[1;36m║ 8  ║ South African Cricket Team               ║\033[0m\n";
		cout << "\033[1;36m║ 9  ║ Sri Lanka Cricket Team                   ║\033[0m\n";
		cout << "\033[1;36m║ 10 ║ Bangladesh Cricket Team                  ║\033[0m\n";
		cout << "\033[1;36m╚════╩══════════════════════════════════════════╝\033[0m\n";

		cout << "\033[1;37mSelect an option: \033[0m";


		cin >> choose;
		switch (choose) {
		case 1:
			copy(user_team, pak_player_names);
			break;
		case 2:
			copy(user_team, eng_player_names);
			break;
		case 3:
			copy(user_team, aus_player_names);
			break;
		case 4:
			copy(user_team, ind_player_names);
			break;
		case 5:
			copy(user_team, nz_player_names);
			break;
		case 6:
			copy(user_team, wi_player_names);
			break;
		case 7:
			copy(user_team, afg_player_names);
			break;
		case 8:
			copy(user_team, sa_player_names);
			break;
		case 9:
			copy(user_team, sri_player_names);
			break;
		case 10:
			copy(user_team, ban_player_names);
			break;
		default:
			cout << "Please select an appropriate option\n";
			break;
		}
	} while (choose > 10 || choose < 1);
}

void scoreboard(int i, string user_team[11], int balls, int wickets, int score, int totalscore, int target) {
	int overs = balls / 6;
	int remaining_balls = balls % 6;
	system("clear");

	// Header
	cout << "\033[1;32m╔══════════════════════════════════════════════════════════╗\033[0m\n";
	cout << "\033[1;32m║\033[0m" 
		 << "\033[1;36m" << setw(15) << left << " Player" 
		 << "\033[1;32m│\033[0m" 
		 << "\033[1;33m" << setw(42) << left << user_team[i]
		 << "\033[1;32m║\033[0m\n";
	cout << "\033[1;32m╠══════════════════════════════════════════════════════════╣\033[0m\n";

	// Overs
	cout << "\033[1;32m║\033[0m" 
		 << "\033[1;36m" << setw(15) << left << " Overs" 
		 << "\033[1;32m│\033[0m" 
		 << "\033[1;33m" << overs << "." << remaining_balls 
		 << setw(39) << " " 
		 << "\033[1;32m║\033[0m\n";
	cout << "\033[1;32m╠══════════════════════════════════════════════════════════╣\033[0m\n";

	// Wickets
	cout << "\033[1;32m║\033[0m" 
		 << "\033[1;36m" << setw(15) << left << " Wickets" 
		 << "\033[1;32m│\033[0m" 
		 << "\033[1;33m" << setw(42) << left << wickets 
		 << "\033[1;32m║\033[0m\n";
	cout << "\033[1;32m╠══════════════════════════════════════════════════════════╣\033[0m\n";

	// Current Score
	cout << "\033[1;32m║\033[0m" 
		 << "\033[1;36m" << setw(15) << left << " Current Score" 
		 << "\033[1;32m│\033[0m" 
		 << "\033[1;33m" << setw(42) << left << score 
		 << "\033[1;32m║\033[0m\n";
	cout << "\033[1;32m╠══════════════════════════════════════════════════════════╣\033[0m\n";

	// Total Score
	cout << "\033[1;32m║\033[0m" 
		 << "\033[1;36m" << setw(15) << left << " Total Score" 
		 << "\033[1;32m│\033[0m" 
		 << "\033[1;33m" << setw(42) << left << totalscore 
		 << "\033[1;32m║\033[0m\n";
	cout << "\033[1;32m╠══════════════════════════════════════════════════════════╣\033[0m\n";

	// Target (if set)
	if (target > 0) {
		cout << "\033[1;32m║\033[0m" 
			 << "\033[1;36m" << setw(15) << left << " Target" 
			 << "\033[1;32m│\033[0m" 
			 << "\033[1;33m" << setw(42) << left << target 
			 << "\033[1;32m║\033[0m\n";
		cout << "\033[1;32m╠══════════════════════════════════════════════════════════╣\033[0m\n";
	}

	cout << "\033[1;32m╚══════════════════════════════════════════════════════════╝\033[0m\n";
}


void waitForKeyPress() {
	cout << "Press any key to continue...\n";
	system("read -n1"); // Waits for any key press
}

void instructions() {

	cout << "\033[1;34m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m\n";
	cout << "\033[1;34m                  INSTRUCTIONS                        \033[0m\n";
	cout << "\033[1;34m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m\n\n";

	// show game play instruction to user
	cout << "\033[1;36m1. \033[1;34mThis is a hand cricket game where you select scores (1-6).\033[0m\n";
	cout << "\033[1;36m2. \033[1;34mIf your score matches the opponent's guess, the player is OUT.\033[0m\n";
	cout << "\033[1;36m3. \033[1;34mYou and the computer take turns batting and bowling.\033[0m\n";
	cout << "\033[1;36m4. \033[1;34mThe team with the highest score wins.\033[0m\n";

	cout << "\033[1;34m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\033[0m\n";

}

int toss_rand() {
	// Generate a random number (0 or 1)
	return rand() % 2;
}

void copy(string x[11], string y[11]) {
	for (int i = 0; i < 11; i++) {
		x[i] = y[i];
	}
}

void decide_winner() {
	if (user_won) {
	cout << "\033[1;32m\n🎉 Congratulations! You won the game! 🏆\033[0m\n";
	} else {
	cout << "\033[1;31m\n💔 Computer wins the game! Better luck next time! 🤖\033[0m\n";
	}
	target = 0; //reset the target incase user wants to play again..
}

void loading() {
	for (int i = 0; i < 3; i++) {
		this_thread::sleep_for(chrono::milliseconds(500)); //loads for 1.5s

	}
}

// function for difficulty level
void difficulty() {
	system("clear");
	int option;
	cout << "\033[1;36m-----Difficulty levels-----\033[0m\n";
	cout << "\033[1;32m1. Easy\033[0m\n";
	cout << "\033[1;33m2. Normal\033[0m\n";
	cout << "\033[1;31m3. Hard\033[0m\n";
	cout << "\033[1;36mSelect option from 1-3: \033[0m";
	cin >> option;
	switch (option) {
		case 1:
			current_difficulty_level = easy;
			cout << "\033[1;32mYou selected difficulty level: Easy\033[0m\n";
			break;
		case 2:
			current_difficulty_level = normal;
			cout << "\033[1;33mYou selected difficulty level: Normal\033[0m\n";
			break;
		case 3:
			current_difficulty_level = hard;
			cout << "\033[1;31mYou selected difficulty level: Hard\033[0m\n";
			break;
		default:
			cout << "\033[1;31mInvalid input. Setting difficulty level as Easy\033[0m\n";
			current_difficulty_level = easy;
			break;
	}
}


void play_sound(const std::string& sound_file) {
    std::string command = "afplay \"" + sound_file + "\"";  // Command to play the MP3 file
    system(command.c_str());  // Execute the command to play the sound
}

void play_background_music(const std::string& music_file) {
    std::string command = "afplay \"" + music_file + "\" &";  // Command to play the MP3 in the background
    system(command.c_str());  // Execute the command to play the music
}


void exit_game() {
    // Uses the 'killall' command to stop the 'afplay' process. This will stop any running music.
    system("killall afplay");
	exit(0);
}

void display_innings_summary(const string team[], const int scores[]) {
	cout << "\n\033[1;32mInnings Summary:\033[0m\n";
	cout << "\033[1;34m------------------------------------------\033[0m\n";
	cout << "\033[1;34m| Player Name                | Runs      |\033[0m\n";
	cout << "\033[1;34m------------------------------------------\033[0m\n";

	for (int j = 0; j < 11; j++) {
		// Format player name and score with alignment
		cout << "\033[1;37m| " << setw(25) << left << team[j]
			 << "| " << setw(10) << right << scores[j] << "|\033[0m\n";
	}

	cout << "\033[1;34m------------------------------------------\033[0m\n\n";
}



/*
FEATURES WE ARE CURRENTLY WORKING ON:

Calculated guesses by Computer!


int predictive_random();
bool start_predictive_guess = false;

int predictive_random(){
	int total_weight = 0;
	for(int i =0; i < max_score; i ++)
	{
		total_weight+=frequency[i];
	}

 
	int random_value = rand() % total_weight;

	int cumulative_weight = 0;
	for(int i =0; i < max_score;i++)
	{
		cumulative_weight+=frequency[i];
		if(random_value < cumulative_weight)
		{
			return i + 1;
		}

	}
	return rand() % 6 + 1;


}
*/