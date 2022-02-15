/*!
 * @brief	���f���p�̒萔�o�b�t�@�B
 */
/*!
 * @brief	���_�V�F�[�_�[�ƃs�N�Z���V�F�[�_�[�p�̒萔�o�b�t�@�B
 *@details
 * �����ύX������tkSkinModel.h��SVSConstantBuffer���ύX����悤�ɁB
 */
cbuffer VSPSCb : register(b0){
	float4x4 mWorld			: packoffset(c0);
	float4x4 mView			: packoffset(c4);
	float4x4 mProj			: packoffset(c8);
	float3 emissionColor	: packoffset(c12);	//���Ȕ����F�B
	int isShadowReceiver	: packoffset(c12.w);	//�V���h�E���V�[�o�[�H
};

/*!
 * @brief	���C�g�p�̒萔�o�b�t�@�B
 *@details
 * �����ύX������tkLightManager.h��SLightParam���ύX����悤�ɁB
 */
cbuffer lightCb : register(b1)
{
	float3 eyePos 			: packoffset(c0);		//�J�����̈ʒu�B
	int numDirectionLight 	: packoffset(c0.w);		//�f�B���N�V�������C�g�̐��B
	float3 ambientLight		: packoffset(c1);		//�A���r�G���g���C�g�B
	int numPointLight		: packoffset(c1.w);		//�|�C���g���C�g�̐��B
	float4 screenParam		: packoffset(c2);		// �X�N���[���p�����[�^(near, far, screenWidth, screenHeight)
	int numEmissionLight	: packoffset(c3);		//���Ȕ������C�g�̐��B
};

cbuffer MaterialParamCb : register(b2){
	int hasNormalMap;			//!<�@���}�b�v����H
	int hasSpecularMap;			//!<�X�y�L�����}�b�v����H
	float anisotropic;			//�ٕ�������
	unsigned int materialID;	//!<�}�e���A��ID�B

};

//���ӁB�V���h�E�}�b�v�̖����𑝂₵����AShadowCb�̃����o�����蓖�ĂĂ��郌�W�X�^�̔ԍ����Ē�������K�v������B
#define NUM_SHADOW_MAP 3 
/*!
 * @brief	�V���h�E�}�b�v�p�̒萔�o�b�t�@�B
 */
cbuffer ShadowCb : register( b3 ){
	float4x4 mLVP[NUM_SHADOW_MAP];		//���C�g�r���[�v���W�F�N�V�����s��B
	float4 texOffset[NUM_SHADOW_MAP];	//�V���h�E�}�b�v�̃T�C�Y�B
	float4 depthOffset;					//�[�x�I�t�Z�b�g�B�V���h�E�A�N�l��������邽�߂̃o�C�A�X�B
										//�l���傫���قǉe�������ɂ����Ȃ�܂��B
	float4  shadowAreaDepthInViewSpace;	//�J������Ԃł̉e�𗎂Ƃ��G���A�̐[�x�e�[�u���B
};

/*!
 * @brief	GBuffer�p�̒萔�o�b�t�@�B
 */
cbuffer GBufferCb : register( b4 ){
	int isPCFShadowMap;
};

/*!
 *@brief	�S���ʎԃV���h�E�p�̒萔�o�b�t�@�B
 */
cbuffer OminiDirectionShadowCb : register( b5 ){
	float4x4 lightViewProjMatrix[6] : packoffset(c0);
	float3 lightPosition			: packoffset(c24);
	float  distanceAffectedByLight  : packoffset(c24.w);
	float  shadowBias				: packoffset(c25);
};