# \<SoundNotes - A Music Discovery App For Enthusiasts\>
 
Authors: \<[Aakif Iqbal](https://github.com/aakifiq)\>, \<[Justin Wang](https://github.com/justin-g-wang)\>, \<[Hassan Fawaz](https://github.com/HassanMFawaz)\>, \<[Fasil Eshetu](https://github.com/feshe001)\>

## Project Description
  * Why is it important or interesting to you?
  This project is interesting to us since every one of us in the group listens to music on a daily basis. However, we realized that if you listen to your self-created playlist over and over , it can get quite repetitive and boring. So what if we could create a program which could recommend us songs based on what we like and popular genres we normally listen to , thus providing us a new enjoyable playlist whenever we want. 
  * What languages/tools/technologies do you plan to use?
  In developing SoundNotes, our music discovery app, we're using C++. For audio processing, we've chosen the BASS library to analyze and process music tracks effectively. Our user interface is being designed with Qt, focusing on simplicity and user-friendliness. We're also utilizing GitHub for version control and collaboration. Lastly, integrating the Spotify Web API is key for accessing a wide range of music and metadata, crucial for our app's recommendation feature. 
  * What will be the input/output of your project?
  The input will be the user’s personal information in order for them to create a profile. This will include first and last name, date of birth, username and password. The user can also enter the name of a song, genres, artists, albums, release date, and even popularity to find specific songs. They will also be able to rate a song between 0.0 - 10.0 The output will be the user having their own custom profile which has a diary of past ratings for all the songs or albums they have rated. They will see a graph showing their rating between 0.0 - 10.0 for all songs or albums. Furthermore, they will see a list of songs and albums based on their recommendations.
  * What are the features that the project provides?
  Song Notes is a music discovery app. It organizes songs and albums into genres and subgenres, simplifying your search for preferred music. Its standout feature is a recommendation system: input a favorite song or artist, and you'll get a list of similar music, using algorithms considering genre, artist, and album. Additionally, you can search music by artist and genre, or filter by release date or popularity. A key aspect of Song Notes is its rating system, where users can rate songs and albums. The ratings you give to songs will adjust future recommendations. It will aslo include a login system, where the user can login into his own profile where all his past rating amd recommendations will be stored.

## User Interface Specification
### Navigation Diagram
https://drive.google.com/file/d/13ZGPLVQwXzsvixa0AvmvoHHTO-zG-gg3/view?usp=sharing

### Screen Layouts
Upon opening the website, users will have to log in or create an account using their personal information if they don’t have one. Once they've logged in, they will be brought to the main page where they can use the search feature, add a new rating or view their account. If they decide to click search they will be able to freely browse the songs, albums, and artists along with their respective information (release date, genre, album cover, artist portrait, etc.). If they decide to add a rating, they will use the search feature to find the media they would like to rate and rate it on a scale of 0.0 to 10.0. They will also be given the option to write a review. If they choose to view their account, they will be met with their media rating graph, media recommendations, the option to view their media diary, and the settings option. If they choose to view their media diary, they will be prompted to select which of the three medias they would like to see a diary of (song, album, artist). Once they select the media, they will see a list of images pertaining to the media they selected alongside the ratings they have given them. If they decide to go to the settings, they will have the option to edit their information or log out. If they log out, they will be brought back to the opening website screen.

### Class Diagram
<img width="558" alt="image" src="https://github.com/cs100/final-project-jwang798-hfawa001-feshe001-aiqba016/assets/127655051/0b2cc173-a9df-4c48-b4cc-7b0a311e6bcb">


* The  superclass that we will be using is the Logging in class. This is because everything that we are doing starts from Logging in. They create their log in information and set it from the beginning. From there on, they are able to make use their account to access ratings, a diary, and change settings. The ratings and diary class cannot exist without a user Account. In the diary class, users will be able to set their ratings when they access diary which will store their ratings.

<img width="677" alt="image" src="https://github.com/cs100/final-project-jwang798-hfawa001-feshe001-aiqba016/assets/127655051/87d7d602-9b94-4a09-ae86-1e81170d06ec">


Single-Responsibility Principle(SRP): At first, we only had one login class. This class asks the user for a username and password. It verifies if the username and password are within the standards recommended. Then it checks if the username and password are valid to grant access to that user.However, this class was updated and separated into two parts. The first class is called askForUserLogin and the second one is called UserLogin.The first class asks for the user login and verifies if the login fits all the criteria and then passes it to user login. UserLogin class verifies if the login works and allows the user to continue working. This change helped the code in making our classes easy to maintain. This way we can change the way login information is collected without affecting the authentication process. Furthermore, it improves scalability as each class is independent which means we can update or replace easily. Furthermore, it makes it easier to test as each class has a single responsibility.
Open-Closed Principle (OCP): "We will add features by extending classes, not changing them. For example, if we want to add a new way to sort songs, we'll create a new class that extends our sorting functionality without altering the existing sorting class."
Liskov Substitution Principle (LSP): "We will add subclasses that can be used just like their parent class without any issues. For instance, if we have a class for basic users, any subclass like 'admin user' or 'guest user' will work just as well when used in place of the basic user class."
Dependency Inversion Principle (DIP): "We will add abstractions between high-level modules and low-level modules. High-level modules will not directly depend on low-level modules; instead, both will depend on interfaces. This means our user login system will interact with a storage interface, not directly with file or database storage."



 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
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
 To install this app and run the application, this Github repository shoud be cloned into an IDE that supports C++ programming. After you clone it, you need to run `cmake .`, `make` , `./SongCollection`. After running `./`SongCollection`, you should be able to find login in, rate music and get recommendations. 
 ## Testing
Our project was tested with Google Test. Everyone who wrote a part of the project also made tests to check if their part worked correctly. Then, they would create a pull request. Another team member would look at what was added and decide if it was okay. This way, we made sure everything worked well before adding it to the main project. We also used valgrind to check for memory leaks.
 
