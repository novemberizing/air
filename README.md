__NOVEMBERIZING AIR__
=====================

<img alt="GitHub issues" src="https://img.shields.io/github/issues/novemberizing/air"> <img alt="GitHub milestones" src="https://img.shields.io/github/milestones/open/novemberizing/air"> <img alt="GitHub" src="https://img.shields.io/github/license/novemberizing/air"> <img alt="GitHub release (latest SemVer)" src="https://img.shields.io/github/v/release/novemberizing/air">

"NOVEMBERIZING AIR"는 안드로이드 기기를 컴퓨터에서 출력하고 제어하는 소프트웨어를 만드는 프로젝트입니다.

![NOVEMBERIZING PLAYER AIR](docs/image/NOVEMBERIZING.AIR.20221208.001.png)

빌드 후에 실행을 하려면

```
adb exec-out screenrecord --time-limit -1 --bit-rate=64m --output-format=h264 --size=1080x2400 - | PlayerAir
```
