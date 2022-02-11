# cub3D
![cub3D_play_capture](https://user-images.githubusercontent.com/58730856/153344101-c8049cbb-9886-4c0b-b615-a9a1ee6c4e02.gif)

<br>

## 개요
cub3d는 [Wolfenstein 3D](http://users.atw.hu/wolf3d/)에서 사용한 렌더링 알고리즘을 활용해 2차원 맵을 3차원으로 렌더링하는 프로그램입니다. <br>
플레이어는 생성된 맵에서 움직여 여러 각도에서 맵을 볼 수 있습니다. 이와 함께 맵 명세(.cub) 파일을 바꾸어 맵 구조, 벽 텍스쳐, 바닥과 천장 색깔을 수정할 수 있습니다.

<br>

## 구현 사항
### Rendering process based on DDA Algorithm
이 프로젝트의 렌더링은 [DDA 알고리즘](https://en.wikipedia.org/wiki/Digital_differential_analyzer_(graphics_algorithm))을 기반합니다. [DDA 알고리즘](https://en.wikipedia.org/wiki/Digital_differential_analyzer_(graphics_algorithm))은 raycast를 할 때, collision detection을 최소화하여 매우 빠른 시간안에 정확한 hit info를 얻을 수 있도록 해줍니다. 이러한 렌더링은 플레이어의 키 입력 때마다 실행됩니다. 이를 통해 카메라 움직임을 구현하였습니다.

### Texture Mapping
렌더링 알고리즘 상에서 벽 텍스쳐를 각 뱡향에 따라 다르게 설정할 수 있고 이를 바르게 매핑할 수 있습니다. 이 때, 각 텍스쳐 파일은 .xpm 포맷으로 한정하였습니다.

### Minimap System
플레이어의 위치를 단순화된 미니맵 UI를 통해 확인할 수 있습니다. 플레이어는 초록색, 벽은 회색으로 칠해져 플레이어의 상대적 위치를 쉽게 알 수 있습니다.

### Wall Coliision
Player는 벽을 통과할 수 없습니다. 이는 키 입력에 따른 플레이어 위치 계산시 부적절한 위치라면 움직임과 렌더링이 일어나지 않도록 함으로써 구현했습니다.

### Invalid Map detection
렌더링할 맵에 대한 명세를 담은 .cub파일이 부적절한 형식인지 테스트하고 적합한 형식이 아니라면 프로그램이 실행되지 않습니다.

<br>

## Usage
```shell
# Installation
git clone https://github.com/JongHyun-GD/cub3d.git
cd ./cub3d
make

# Execute
./cub3d [map_path]
# ex) ./cub3d ./assets/maps/map01_sample.cub

# Key Mapping
# W = Move foward
# S = Move backward
# A = Move left
# D = Move right
# left arrow key = Turn left
# right arrow key = Turn right
# ESC = Exit
```

<br>

## 개발 기간
6주 (2021.12.27 ~ 2022.02.09)

<br>

## Contributors
[박종현](https://github.com/JongHyun-GD) | `Rendering algorithm`, `Collision Detection`, `Texture Mapping`

[손대호](https://github.com/sondho) | `Parsing map file`, `Error Detection on map file`, `Minimap system`
