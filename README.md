# AUTHOR:         [DAVID OJEIFO](https://github.com/Kingvadee).
# COHORT:         13.
# Repo:           alx-maze_project:tv::video_game::dart:
# Tasks :page_with_curl:

# Background Context:bulb:
   *  The goal of this project is to create a game in 3D using raycasting !:video_game:
      You don¿t have to do the tasks in order, except for the first one (obviously),
      or if a task depends on a previous one.
   *  You have a link :link: to a very good and very long tutorial about raycasting in the :point_right: [Tips and links.](https://s3.amazonaws.com/alx-intranet.hbtn.io/uploads/misc/2021/1/9da3b82dc0bcfea07858b70956de47f0e2db2dad.pdf?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIARDDGGGOUSBVO6H7D%2F20231114%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20231114T181815Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=ca81f04ee1d4fa253ae436e324d8060e0c4706fea99e41eaf45e6554e88db015) section in the [README_file](https://github.com/Kingvadee/alx-maze_project./blob/master/README.md)below :point_down:
      so read it very carefully, and practice !
   *  *Please have a lot of fun doing this project ! :smile::grin::grinning:
# ![image](https://s3.amazonaws.com/alx-intranet.hbtn.io/uploads/medias/2020/9/8970c3ee63d8149b93e30229276c3f7580ac9447.gif?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIARDDGGGOUSBVO6H7D%2F20231121%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20231121T125358Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=6f624411f11502e4b1e3e5999e70b3d228f82dd523a7593c82db378bffd5487f)

# Requirements:point_down:
 * All your files will be compiled on `Ubuntu 14.04 LTS`, using `gcc`
   (`Ubuntu 4.8.4-2ubuntu1~14.04`) `4.8.4`
 * We will use the **`gcc` flags** `-Wall` `-Werror` `-Wextra` and `-pedantic`
 * All your functions must be commented
 * Your functions should be **maximum 40** lines long (one statement per line)
 * Your functions should be **maximum 80** columns long
 * No more than **5 functions** per file
 * Your entire repository will be checked using Betty
 * Don't push any object files `.o` or temporary files `*~`, or any unused
   source file if you don't want to lose points !
 * It is advised to always keep a clear organisation in your repository.
   For example, store all your sources in a `src` directory, and all your
   headers in a `inc`, `headers` or `dependencies` folder.

### Tips and links:bulb:&:link:
 * Simple DirectMedia Layer(SDL) Version 2.0
---
[SDL2](https://www.libsdl.org/)
 * Simple DirectMedia Layer is a cross-platform development library designed to provide low level access to audio, keyboard, mouse, joystick, and graphics hardware via OpenGL and Direct3D. It is used by video playback software,emulators, and popular games including Valve's award winning catalog and many Humble Bundle games.

 * [SDL2 - Get started.pdf](https://intranet.alxswe.com/rltoken/pMnvq93vpbAh9q6inKQMuQ)
 * [SDL2 tutorials](https://intranet.alxswe.com/rltoken/oona0Kd1yVyjHQGoJaV_aw)
 * Be careful with tutorials/help online: We are using `SDL2`, and not `SDL-1.2` !
 * [RAYCASTING !!!](https://intranet.alxswe.com/rltoken/vRw7CP21mUmKFDdrQjQ2GA)
 * [Alternative Raycasting Tutorial](https://intranet.alxswe.com/rltoken/dnQwzgrDUEhFXIF8sNivkg)
 * Don¿t forget to **install SDL2** [SDL2 tutorials](https://intranet.alxswe.com/rltoken/oona0Kd1yVyjHQGoJaV_aw)
 * There are no forbidden functions for this project. You are allowed to use any
   system call and/or standard library function.
 * You are allowed to use [all the functions provided by SDL2](https://intranet.alxswe.com/rltoken/bmGynXNHzUObCE08XuoCQg)
#### TASK: :page_with_curl:
 * **0. Walls !**
 * In this first part, you¿ll have to:
 * 1.	Create a window with SDL2
 * 2.	Use raycasting to draw walls on your window !
 * 3.	You don¿t need to be able to rotate the camera during the execution in this part,
   	but you must provide a way to change the angle of the camera in your code to see
  	if it works after recompiling it.
 * 4.	The color of the walls must be different from the color of the ground/ceil
 * 5.	The map doesn¿t need to be parsed from a file, but you must provide a way to modify
   	it in your code to see if it works after recompiling it. (e.g. using an array of
   	arrays of integers or characters).
 * **EXAMPLE:**
# ![image](https://s3.amazonaws.com/alx-intranet.hbtn.io/uploads/medias/2020/9/7e897a79ffe0d990856e021f4e1e6cdbb0ff5395.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIARDDGGGOUSBVO6H7D%2F20231121%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20231121T125358Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=b7f1eacb86e6ff22ce3e6fee6a46172b5c5e6969b5afe320c673d6c3f537f97f)
 * In the following image, the camera is the red square, and the visible area is painted in green:

