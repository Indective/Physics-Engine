# Indective's AABB Physics Engine

Well, some time around the 1660s, a normal French guy was sitting under a tree when an apple fell on his head. Inspired by that discovery, we now understand gravity — and this engine brings the basics of physics to life for **axis-aligned boxes (AABBs)** in 2D.

Using **C++17**, **Raylib**, and some physics magic, this engine simulates realistic box behavior, including falling, collisions, and resting on the ground.

---

## Physics Overview

This engine implements a **basic 2D physics simulation** for AABB objects, focusing on:

- **Gravity**  
  Each object experiences a downward acceleration, simulating natural falling motion.  

- **Velocity Integration**  
  Positions are updated based on velocity and acceleration:
  velocity += acceleration * dt
  position += velocity * dt
  This simple Euler integration gives smooth motion over frames.

- **Ground Collision Detection**  
  Objects detect when their bottom edge intersects the top of the ground. A small tolerance prevents jittering caused by floating-point errors.  

- **Collision Response**  
  When a collision with the ground is detected:
  - The object’s vertical velocity is zeroed (so it stops falling).  
  - The grounded state is set, allowing further logic like jumping or friction.  

- **Friction / Damping (Optional)**  
  Horizontal velocity can be slightly reduced when grounded to simulate surface friction.

> ⚠️ Note: This engine **does not use Swept AABB or Continuous Collision Detection (CCD)**, so very fast objects can tunnel through colliders.


## Features

- Axis-Aligned Bounding Box (AABB) collision detection  
- Gravity simulation with adjustable acceleration  
- Stable grounded detection with floating-point tolerance  
- Horizontal velocity damping for friction  
- Lightweight and easy to integrate in Raylib projects  


## Limitations

- **Discrete collision detection only** — fast-moving objects may skip collisions.  
- **Axis-aligned only** — no rotations or complex shapes.  
- **Single ground plane** — multiple platforms require additional handling.  
- **No advanced collision resolution** — stacking or sliding is minimal.


## Planned Improvements

- Implement Swept AABB / CCD to prevent tunneling
- Support multiple platforms and stacked boxes


## Dependencies

- **Raylib**
- **C++17 compatible compiler**
- **CMake**

## Usage

Simply clone the repo and build it with cmake, then run the exc named "engine" to get going.

## License

This project is licensed under the MIT license ; [MIT](./LICENSE)
