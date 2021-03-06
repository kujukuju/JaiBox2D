EXPORT b2JointDef* JointDef_new();
EXPORT b2JointDef JointDef_create();
EXPORT void linear_stiffness(float* stiffness, float* damping, float frequencyHertz, float dampingRatio, const b2Body* bodyA, const b2Body* bodyB);
EXPORT void angular_stiffness(float* stiffness, float* damping, float frequencyHertz, float dampingRatio, const b2Body* bodyA, const b2Body* bodyB);
EXPORT b2JointType Joint_get_type(b2Joint* self);
EXPORT b2Body* Joint_get_body_a(b2Joint* self);
EXPORT b2Body* Joint_get_body_b(b2Joint* self);
EXPORT b2Vec2 Joint_get_anchor_a(b2Joint* self);
EXPORT b2Vec2 Joint_get_anchor_b(b2Joint* self);
EXPORT b2Vec2 Joint_get_reaction_force(b2Joint* self, float inv_dt);
EXPORT float Joint_get_reaction_torque(b2Joint* self, float inv_dt);
EXPORT b2Joint* Joint_get_next(b2Joint* self);
EXPORT void* Joint_get_user_data(b2Joint* self);
EXPORT void Joint_set_user_data(b2Joint* self, void* data);
EXPORT bool Joint_is_enabled(b2Joint* self);
EXPORT bool Joint_get_collide_connected(b2Joint* self);
EXPORT void Joint_dump(b2Joint* self);
EXPORT void Joint_shift_origin(b2Joint* self, const b2Vec2* newOrigin);
EXPORT void Joint_draw(b2Joint* self, b2Draw* draw);