# \<SoundNotes - A Music Discovery App For Enthusiasts\>
 
Authors: \<[Aakif Iqbal](https://github.com/aakifiq)\>, \<[Justin Wang](https://github.com/justin-g-wang)\>, \<[Hassan Fawaz](https://github.com/HassanMFawaz)\>, \<[Fasil Eshetu](https://github.com/feshe001)\>

## Project Description
  * Why is it important or interesting to you?
  This project is interesting to us since every one of us in the group listens to music on a daily basis. However, we realized that if you listen to your self-created playlist over and over , it can get quite repetitive and boring. So what if we could create a program which could recommend us songs based on what we like and popular genres we normally listen to , thus providing us a new enjoyable playlist whenever we want. 
  * What languages/tools/technologies do you plan to use?
  In developing SoundNotes, our music discovery app, we're using C++. Our user interface is based on the terminal focusing on simplicity and user-friendliness. We're also utilizing GitHub for version control and collaboration. Lastly, we integrating a csv file consisting of over 100,000 songs for accessing a wide range of music and metadata, crucial for our app's recommendation feature. 
  * What will be the input/output of your project?
The UI is based on terminal, therefore the user will need to enter numbers for them to move around through the UI. More inputs will be the user’s personal information in order for them to create a account and  profile. This will include first and last name, date of birth, username and password. The user can also enter the name of a song, genres, artists, albums, and even popularity to find specific songs. They will also be able to rate a song between 0- 10.
*The output will be the user having their own custom profile which has a diary of past ratings for all the songs or albums they have rated. Furthermore, they will see a list of songs and albums based on their recommendations.

* What are the features that the project provides?
Song Notes is a music discovery app. It organizes songs and albums into genres and subgenres, simplifying your search for preferred music. Its standout feature is a recommendation system: input a favorite song or artist, and you'll get a list of similar music, using algorithms considering genre, artist, and album. Additionally, you can search music by artist and genre, or filter by release date or popularity. A key aspect of Song Notes is its rating system, where users can rate songs and albums. The ratings you give to songs will adjust future recommendations. It will aslo include a login system, where the user can login into his own profile where all his past rating amd recommendations will be stored.

## User Interface Specification
### Navigation Diagram
https://drive.google.com/file/d/13ZGPLVQwXzsvixa0AvmvoHHTO-zG-gg3/view?usp=sharing

### Screen Layouts
Upon opening the website, users will have to log in or create an account using their personal information if they don’t have one. Once they've logged in, they will be brought to the main page where they can use the search feature, add a new rating or view their account. If they decide to click search they will be able to freely browse the songs, albums, and artists along with their respective information (release date, genre, album cover, artist portrait, etc.). If they decide to add a rating, they will use the search feature to find the media they would like to rate and rate it on a scale of 0.0 to 10.0. They will also be given the option to write a review. If they choose to view their account, they will be met with their media rating graph, media recommendations, the option to view their media diary, and the settings option. If they choose to view their media diary, they will be prompted to select which of the three medias they would like to see a diary of (song, album, artist). Once they select the media, they will see a list of images pertaining to the media they selected alongside the ratings they have given them. If they decide to go to the settings, they will have the option to edit their information or log out. If they log out, they will be brought back to the opening website screen.

### Class Diagram
<img width="544" alt="image" src="https://github.com/cs100/final-project-jwang798-hfawa001-feshe001-aiqba016/assets/127655051/a0d5ef5d-86e3-4815-b396-c085aa737b00">


* The  starting clss that we will be using is the userLogin class. This is because everything that we are doing starts from Logging in. They create their account which gets stored into a file. The UserApplication class interacts directly with UserStorage for user management and UserAuthentication for login procedures. It depends on: UserStorage, UserAuthentication, and indirectly on UserProfile through UserStorage The UserStorage class has composition with UserProfile because it manages user data persistently. It also depends on UserProfile. The UserProfle class represents individual user data but it is used within UserStorage. The UserAuthentication class uses UserStorage to verify user credentials and depends on UserStorage. The Diary class depends on SongCollection and Song for managing diary entires related to songs, albums, and artists. It is associated with the UserApplication to manage user-specific diaries. The Ratings class depends on Diary and indirectly on SongCollection and Song for managing and retrieving ratings. It is also associated with Diary when retrieving the user-specific diary. 

Single Responsibility Principle (SRP): UserStorage manages user data storage, UserProfile represents user information, UserAuthentication handles authentication, Diary manages song-related data for users, and Ratings manages ratings for songs, albums, and artists.

Open/Closed Principle (OCP): The system is designed in a way that allows for extension without modification. For instance, if new functionalities related to user profiles or diary entries need to be added, new classes can be introduced without altering existing code, adhering to the OCP.

Liskov Substitution Principle (LSP): This principle is not demonstrated, as there's no inheritance hierarchy among the classes. However, the principle could be applied in areas like extending UserProfile for different types of users or expanding the Diary class to support different types of diary entries, ensuring that subclasses could be used in place of their parent classes without altering the desirable properties of the program.

Interface Segregation Principle (ISP): While not explicitly shown through interface usage , the principle is conceptually applied through focused class responsibilities, suggesting that if interfaces were used, they would likely be small and specific to avoid forcing any class to implement methods it doesn't use.

Dependency Inversion Principle (DIP): We do not fully adhere to the Dependency Inversion Principle (DIP), as UserAuthentication directly depends on the concrete class UserStorage. To address this and align with DIP, we plan to introduce an interface for user storage operations, allowing UserAuthentication to depend on this abstraction instead of the concrete implementation, thus decoupling high-level and low-level modules.
 
 ## Screenshots
 
<img width="507" alt="Screenshot 2024-03-15 at 12 32 13 PM" src="https://github.com/cs100/final-project-jwang798-hfawa001-feshe001-aiqba016/assets/156469475/6f9344e1-0b95-43f9-b1de-93754855952f">
<img width="1119" alt="Screenshot 2024-03-15 at 12 30 36 PM" src="https://github.com/cs100/final-project-jwang798-hfawa001-feshe001-aiqba016/assets/156469475/7e12dc4b-48f1-4448-9b39-cf348fc5e36c">
<img width="770" alt="Screenshot 2024-03-15 at 12 32 23 PM" src="https://github.com/cs100/final-project-jwang798-hfawa001-feshe001-aiqba016/assets/156469475/a3919e5b-d602-4e8f-b893-0060f6b47ade">
<img width="453" alt="Screenshot 2024-03-15 at 12 32 32 PM" src="https://github.com/cs100/final-project-jwang798-hfawa001-feshe001-aiqba016/assets/156469475/9b3f3c0c-51db-434e-8fc3-68750853d19f">
<img width="999" alt="Screenshot 2024-03-15 at 12 30 50 PM" src="https://github.com/cs100/final-project-jwang798-hfawa001-feshe001-aiqba016/assets/156469475/a3df2bd4-9aeb-4025-8dee-16c4896d95c9">
<img width="510" alt="Screenshot 2024-03-15 at 12 32 38 PM" src="https://github.com/cs100/final-project-jwang798-hfawa001-feshe001-aiqba016/assets/156469475/793a5776-5a7a-4088-9689-c8d5d0aa9f49">
<img width="687" alt="Screenshot 2024-03-15 at 12 33 19 PM" src="https://github.com/cs100/final-project-jwang798-hfawa001-feshe001-aiqba016/assets/156469475/9bdb739b-0ba0-4353-b1f6-0aa93e105338">
<img width="458" alt="Screenshot 2024-03-15 at 12 33 36 PM" src="https://github.com/cs100/final-project-jwang798-hfawa001-feshe001-aiqba016/assets/156469475/28088294-7410-46fc-9904-b580eaaba2ad">
<img width="1123" alt="Screenshot 2024-03-15 at 12 36 42 PM" src="https://github.com/cs100/final-project-jwang798-hfawa001-feshe001-aiqba016/assets/156469475/87f9c943-0619-44d0-85a0-303bebb1a5d5">
<img width="422" alt="Screenshot 2024-03-15 at 12 36 52 PM" src="https://github.com/cs100/final-project-jwang798-hfawa001-feshe001-aiqba016/assets/156469475/9cabe395-375c-4e8c-bfb9-20982ea09fda">
<img width="893" alt="Screenshot 2024-03-15 at 12 45 15 PM" src="https://github.com/cs100/final-project-jwang798-hfawa001-feshe001-aiqba016/assets/156469475/4c4f71d7-ef89-4e20-b9bb-537e61ba61a8">
<img width="424" alt="Screenshot 2024-03-15 at 12 45 31 PM" src="https://github.com/cs100/final-project-jwang798-hfawa001-feshe001-aiqba016/assets/156469475/dd8836a6-0ee3-49b6-bc83-c2baaf96475c">
<img width="351" alt="Screenshot 2024-03-15 at 12 46 26 PM" src="https://github.com/cs100/final-project-jwang798-hfawa001-feshe001-aiqba016/assets/156469475/b8edbbd7-de65-48be-9f08-4444b40ec85e">



 ## Installation/Usage
 To install this app and run the application, this Github repository shoud be cloned into an IDE that supports C++ programming. After you clone it, you need to run `cmake .`, `make` , `./SongCollection`. After running `./SongCollection`, you should be able to find login in, rate music and get recommendations. To run the google tests , you will have to run the command `./googleTest` . To run valgrind you must use `$ valgrind --leak-check=full ./example1`.
 ## Testing
Our project was tested with Google Test. Everyone who wrote a part of the project also made tests to check if their part worked correctly. Then, they would create a pull request. Another team member would look at what was added and decide if it was okay. This way, we made sure everything worked well before adding it to the main project. We also used valgrind to check for memory leaks.
 
