# \<SoundNotes - A Music Discovery App For Enthusiasts\>
 
 > Authors: \<[Aakif Iqbal](https://github.com/aakifiq)\>, \<[Justin Wang](https://github.com/justin-g-wang)\>, \<[Hassan Fawaz](https://github.com/HassanMFawaz)\>, \<[Fasil Eshetu](https://github.com/feshe001)\>

 > You will be forming a group of **FOUR** students and working on an interesting project. The project has 4 phases, each one with specific requirements. A list of proposed project ideas that have been successful in previous quarters is listed in the project specifications document on Canvas. You can select an idea from the list and start thinking about the features you will implement. If you want to propose your own original idea, you will have to contact your instructor to discuss the project and obtain written permission before you submit your project proposal (Phase 1). The project work should be divided almost equally among team members. You can of course help each other, but it needs to be clear who will be responsible for which features. Additionally, you are expected to follow Scrum patterns, specifically the use of a Scrum (Project) board, Sprints, and Scrum meetings.

 > ## Expectations
 > * The backend of your project should be implemented in C++. If you wish to choose anoher programming language (e.g. Java, Python), please discuss with your lab TA to obtain permission.
 > * You can incorporate additional technologies/tools but they must be approved (in writing) by the instructor or the TA.
 > * Each member of the group **must** be committing code regularly and make sure their code is correctly attributed to them. We will be checking attributions to determine if there was equal contribution to the project.
 > * **Each member of the group must actively participate in the Github Project board, writing unit tests, and reviewing commited code.**
> * All project phases are to be submitted to this GitHub repository. You should modify this README file to reflect the different phases of the project. In addition, you should regularly hold sprint meetings with your group. You will need to hold two to three scrum/check-in meetings with your lab TA/reader at different times in addition to the final demo.

## Project Description
  * Why is it important or interesting to you?
  This project is interesting to us since every one of us in the group listens to music on a daily basis. However, we realized that if you listen to your self-created playlist over and over , it can get quite repetitive and boring. So what if we could create a program which could recommend us songs based on what we like and popular genres we normally listen to , thus providing us a new enjoyable playlist whenever we want. 
  * What languages/tools/technologies do you plan to use?
  In developing SoundNotes, our music discovery app, we're using C++. For audio processing, we've chosen the BASS library to analyze and process music tracks effectively. Our user interface is being designed with Qt, focusing on simplicity and user-friendliness. We're also utilizing GitHub for version control and collaboration. Lastly, integrating the Spotify Web API is key for accessing a wide range of music and metadata, crucial for our app's recommendation feature. 
  * What will be the input/output of your project?
  The input will be the user’s personal information in order for them to create a profile. This will include first and last name, date of birth, username and password. The user can also enter the name of a song, genres, artists, albums, release date, and even popularity to find specific songs. They will also be able to rate a song between 0.0 - 10.0 The output will be the user having their own custom profile which has a diary of past ratings for all the songs or albums they have rated. They will see a graph showing their rating between 0.0 - 10.0 for all songs or albums. Furthermore, they will see a list of songs and albums based on their recommendations.
  * What are the features that the project provides?
  Song Notes is a music discovery app. It organizes songs and albums into genres and subgenres, simplifying your search for preferred music. Its standout feature is a recommendation system: input a favorite song or artist, and you'll get a list of similar music, using algorithms considering genre, artist, and album. Additionally, you can search music by artist and genre, or filter by release date or popularity. A key aspect of Song Notes is its rating system, where users can rate songs and albums. The ratings you give to songs will adjust future recommendations. It will aslo include a login system, where the user can login into his own profile where all his past rating amd recommendations will be stored.
 > ## Phase II
 > In addition to completing the "User Interface Specification" and "Class Diagram" sections below, you will need to:
 > * Create an "Epic" (note) for each feature. Place these epics in the `Product Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Break down the "Epics" into smaller actionable user stories (i.e. smaller development tasks). Convert them into issues and assign them to team members. Place these in the `TODO` column (aka Sprint Backlog).
 >   * These cards should represent roughly 7 days worth of development time for your team. Then, once the sprint is over you should be repeating these steps to plan a new sprint, taking you until your second scrum meeting with the reader in phase III.
 > * Schedule two check-ins using Calendly. Both time slots should be during your lab on week 6. Your entire team must be present for both check-ins.
 >   * The first check-in needs to be scheduled with your lab TA. During that meeting, you will discuss your project design/class diagram from phase II.
 >   * The second check-in should be scheduled with a reader. During that meeting you will discuss:
 >     * The tasks you are planning for the first sprint
 >     * How work will be divided between the team members
## User Interface Specification
 > Include a navigation diagram for your screens and the layout of each of those screens as desribed below. For all the layouts/diagrams, you can use any tool such as PowerPoint or a drawing program. (Specification requirement is adapted from [this template](https://redirect.cs.umbc.edu/~mgrass2/cmsc345/Template_UI.doc))

### Navigation Diagram
> Draw a diagram illustrating how the user can navigate from one screen to another. Here is an [example](https://creately.com/diagram/example/ikfqudv82/user-navigation-diagram-classic?r=v). It can be useful to label each symbol that represents a screen so that you can reference the screens in the next section or the rest of the document if necessary. Give a brief description of what the diagram represents.
https://drive.google.com/file/d/13ZGPLVQwXzsvixa0AvmvoHHTO-zG-gg3/view?usp=sharing

### Screen Layouts
Upon opening the website, users will have sign in. They will be presented with options to create an account or log in. If the user clicks to create an account, they will me taken to a page where they must enter the required information. Otherwise, they will be take to the main menu. They will be allowed the option to freely browse the songs, albums, and artists available for rating on the website, along with their respective information (release date, genre, album cover, artist portrait, etc.), using the search feature. On the main page  they can again use the search feature along with two additional ones: add rating and view account. If they decide to add a rating, they will use the search feature to find the media they would like to rate and rate it on a scale of 0.0 to 10.0. They will also be given the option to write a review. If they choose to view their account, they will be met with their media rating graph, media recommendations, the option to view their media diary, and the settings option. If they choose to view their media diary, they will be prompted to select which of the three medias they would like to see a diary of (song, album, artist). Once they select the media, they will see a list of images pertaining to the media they selected alongside the ratings they have given them. If they decide to go to the settings, they will have the option to edit their information or log out. If they log out, they will be brought back to the opening website screen.

### Class Diagram
[Class Diagram.pdf](https://github.com/cs100/final-project-jwang798-hfawa001-feshe001-aiqba016/files/14256026/Class.Diagram.pdf)

* The main class that we will be using is the User Account class. This is because everything that we are doing starts from the user's account. They create their log in information and set it from the beginning. From there on, they are able to make ratings, a diary, and change settings. The ratings and diary class are derived classes from user Account. They will take the user information and using that, the user is able to set ratings for songs, albums, and artists. When the user sets these ratings, it will go into a diary which keeps tracks of all the things they have rated. The diary will also recommend them songs, artists, and albums based on their ratings. 


 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * You should also make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
