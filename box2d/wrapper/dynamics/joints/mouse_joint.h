EXPORT b2MouseJointDef* MouseJointDef_new();
EXPORT b2MouseJointDef MouseJointDef_create();
EXPORT b2Vec2 MouseJoint_get_anchor_a(b2MouseJoint* self);
EXPORT b2Vec2 MouseJoint_get_anchor_b(b2MouseJoint* self);
EXPORT b2Vec2 MouseJoint_get_reaction_force(b2MouseJoint* self, float inv_dt);
EXPORT float MouseJoint_get_reaction_torque(b2MouseJoint* self, float inv_dt);
EXPORT void MouseJoint_set_target(b2MouseJoint* self, const b2Vec2* target);
EXPORT b2Vec2 MouseJoint_get_target(b2MouseJoint* self);
EXPORT void MouseJoint_set_max_force(b2MouseJoint* self, float force);
EXPORT float MouseJoint_get_max_force(b2MouseJoint* self);
EXPORT void MouseJoint_set_stiffness(b2MouseJoint* self, float stiffness);
EXPORT float MouseJoint_get_stiffness(b2MouseJoint* self);
EXPORT void MouseJoint_set_damping(b2MouseJoint* self, float damping);
EXPORT float MouseJoint_get_damping(b2MouseJoint* self);
EXPORT void MouseJoint_dump(b2MouseJoint* self);
EXPORT void MouseJoint_shift_origin(b2MouseJoint* self, const b2Vec2* newOrigin);