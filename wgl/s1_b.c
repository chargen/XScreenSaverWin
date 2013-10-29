#include "gllist.h"
static const float data[]={
	-0.137893f,0.043508f,-0.125711f,
	-0.095845f,-0.165656f,0.072892f,
	-0.093165f,0.152051f,0.327744f,
	-0.003795f,0.001470f,-0.102225f,
	0.152845f,-0.430757f,-0.031907f,
	-0.118828f,0.399389f,0.091047f,
	-0.169137f,-0.181241f,-0.288763f,
	0.048660f,0.018262f,-0.035049f,
	0.008859f,0.208004f,-0.059048f,
	-0.009212f,-0.042229f,-0.000692f,
	-0.040025f,0.115695f,0.178962f,
	-0.198525f,0.018630f,0.257202f,
	0.205081f,-0.244569f,0.136314f,
	-0.214336f,-0.149946f,-0.006872f,
	0.245675f,-0.227316f,-0.184201f,
	-0.001494f,0.259139f,-0.260652f,
	0.070243f,0.038750f,0.069425f,
	-0.033229f,-0.259151f,0.298856f,
	0.088773f,-0.065324f,0.260294f,
	0.009195f,0.078651f,0.055543f,
	-0.090795f,0.025672f,0.056988f,
	-0.163707f,-0.011627f,-0.096395f,
	0.068886f,0.257031f,-0.264175f,
	-0.018086f,-0.285526f,0.152989f,
	-0.017489f,0.031671f,0.000107f,
	-0.075583f,-0.097617f,0.030074f,
	0.129221f,-0.087628f,0.171748f,
	-0.007530f,-0.084194f,0.186045f,
	0.474638f,0.004818f,0.200460f,
	0.016796f,0.096614f,-0.221351f,
	0.187032f,0.031017f,0.039986f,
	-0.142119f,-0.105297f,-0.100849f,
	0.142768f,-0.313960f,-0.349716f,
	-0.146805f,0.140482f,0.035653f,
	0.039939f,-0.051822f,-0.017672f,
	0.057111f,-0.075686f,-0.103478f,
	0.049696f,-0.135070f,0.055097f,
	0.030271f,0.075412f,-0.103571f,
	0.100158f,-0.022917f,0.073895f,
	0.085544f,-0.273613f,0.092456f,
	0.077489f,-0.309836f,-0.003664f,
	-0.017590f,-0.127869f,0.153118f,
	-0.157014f,-0.242184f,0.070478f,
	-0.018167f,-0.133639f,-0.174937f,
	-0.106973f,-0.189783f,0.038622f,
	-0.000096f,0.104429f,-0.032589f,
	-0.032036f,-0.021493f,0.279829f,
	-0.093181f,-0.058024f,0.182239f,
	0.012941f,-0.010409f,0.088080f,
	0.256718f,-0.118137f,-0.078847f,
	-0.113382f,0.135060f,0.269946f,
	0.175810f,-0.026321f,0.013860f,
	-0.110606f,-0.023553f,-0.255525f,
	0.007163f,0.068674f,0.010214f,
	0.031631f,-0.170381f,-0.174604f,
	0.117242f,0.014353f,-0.021215f,
	0.090315f,0.161755f,0.074427f,
	0.285616f,0.335824f,-0.083891f,
	-0.145763f,0.109292f,0.121340f,
	-0.147459f,-0.041936f,0.010427f,
	-0.082626f,0.151300f,-0.030875f,
	0.217154f,-0.288504f,-0.202483f,
	0.026532f,-0.106796f,0.121041f,
	0.046695f,-0.033673f,-0.043721f,
	0.135596f,0.217426f,-0.219631f,
	0.137627f,0.026335f,-0.082390f,
	-0.031665f,-0.115897f,0.077834f,
	-0.214922f,-0.162169f,0.073035f,
	-0.076108f,0.200481f,0.036119f,
	0.012715f,-0.161921f,0.179804f,
	0.140409f,-0.165899f,-0.005149f,
	-0.054606f,0.011149f,0.045768f,
	0.116640f,-0.180314f,0.045320f,
	0.342166f,0.295895f,-0.049250f,
	-0.133242f,0.129064f,0.136969f,
	0.137520f,-0.387145f,0.132137f,
	0.023302f,0.194298f,-0.066187f,
	0.089302f,0.128683f,-0.072530f,
	-0.141374f,0.035924f,-0.079354f,
	-0.209233f,0.018987f,-0.004193f,
	0.156295f,-0.034087f,0.344315f,
	-0.005946f,0.039791f,0.071862f,
	0.076043f,-0.094430f,0.090122f,
	0.127394f,0.031466f,-0.028015f,
	-0.061000f,0.169741f,-0.127635f,
	-0.015117f,-0.160883f,-0.095443f,
	-0.185998f,-0.182942f,0.056857f,
	0.016499f,-0.308118f,-0.075513f,
	0.024971f,-0.301226f,-0.027251f,
	-0.035944f,0.061566f,0.013883f,
	0.007215f,0.046198f,-0.227891f,
	0.189165f,0.079471f,-0.067849f,
	0.026963f,0.027982f,-0.050419f,
	-0.050896f,0.069604f,-0.196938f,
	0.064274f,-0.205263f,0.297868f,
	-0.047543f,0.147822f,0.166593f,
	0.010318f,-0.002148f,0.029434f,
	0.036107f,-0.523568f,-0.118442f,
	-0.199410f,0.233526f,-0.161289f,
	-0.047441f,-0.013973f,0.112998f,
	-0.043494f,-0.181796f,0.065864f,
	-0.074984f,0.177758f,-0.156470f,
	0.225216f,0.081058f,-0.169876f,
	-0.041510f,0.025763f,-0.231350f,
	0.259015f,0.274641f,0.018290f,
	0.039196f,0.010028f,0.072771f,
	0.031646f,0.075290f,0.039258f,
	0.052930f,-0.034809f,0.165429f,
	-0.072511f,0.095786f,-0.222144f,
	0.038706f,0.032296f,-0.002495f,
	0.011675f,-0.061944f,0.082555f,
	-0.168400f,0.074113f,0.049321f,
	0.001263f,-0.207436f,0.013949f,
	-0.027045f,0.015697f,-0.047831f,
	0.121989f,-0.043014f,-0.004426f,
	0.238374f,-0.320060f,-0.111754f,
	0.095077f,0.014640f,0.070665f,
	-0.084367f,0.016444f,0.000788f,
	-0.117804f,0.113550f,0.087029f,
	-0.109080f,-0.155795f,0.040085f,
	-0.020370f,0.118787f,0.101787f,
	0.140877f,-0.144829f,0.107720f,
	-0.247002f,-0.454632f,0.070535f,
	-0.016278f,-0.111440f,0.270110f,
	-0.017624f,-0.146232f,0.154626f,
	0.214030f,0.041025f,-0.170250f,
	0.010009f,-0.159290f,-0.076895f,
	0.116168f,0.156775f,-0.077935f,
	0.199355f,0.081120f,0.003352f,
	0.054178f,-0.036863f,-0.004573f,
	-0.015149f,0.057005f,-0.008878f,
	0.374758f,-0.007823f,-0.078051f,
	-0.034977f,0.026837f,0.035441f,
	0.101867f,0.121954f,0.040450f,
	-0.136911f,0.010061f,0.082698f,
	0.121665f,-0.589852f,0.106401f,
	-0.064574f,0.098679f,0.059336f,
	0.103037f,-0.075263f,0.172586f,
	-0.217492f,-0.170584f,-0.025846f,
	0.260366f,0.002117f,0.041535f,
	-0.024112f,-0.023437f,-0.088146f,
	-0.007767f,0.061738f,0.116208f,
	0.253471f,0.113278f,0.231012f,
	-0.011399f,0.116962f,-0.037465f,
	0.233898f,0.226108f,0.077176f,
	-0.004640f,0.209191f,-0.091738f,
	0.093995f,0.328937f,0.245098f,
	0.155739f,-0.327971f,-0.115265f,
	0.125306f,0.174931f,0.130030f,
	0.005005f,-0.022310f,0.120651f,
	0.046982f,-0.058839f,-0.097958f,
	-0.059618f,-0.068114f,0.070137f,
	0.053184f,-0.081163f,0.000020f,
	0.188066f,-0.082942f,-0.013689f,
	-0.161390f,-0.335891f,-0.060737f,
	0.131189f,0.036733f,-0.093511f,
	-0.002496f,-0.059035f,-0.084055f,
	0.109820f,-0.235531f,0.130865f,
	0.018909f,0.062351f,0.111532f,
	0.123548f,0.094008f,0.056761f,
	0.106710f,-0.049834f,-0.147748f,
	0.102940f,-0.113169f,0.191710f,
	-0.028647f,0.128038f,-0.104189f,
	0.107226f,-0.220633f,-0.147310f,
	-0.205747f,0.063433f,-0.026135f,
	-0.064614f,0.096963f,-0.080108f,
	-0.083255f,0.113008f,-0.089852f,
	0.180961f,-0.269100f,0.115523f,
	0.044722f,-0.023285f,0.024813f,
	0.078986f,0.037242f,0.005124f,
	0.115141f,0.124478f,-0.034603f,
	0.022454f,0.155937f,-0.096183f,
	0.175318f,0.007233f,-0.138507f,
	0.019182f,-0.037869f,0.074242f,
	0.058218f,0.212269f,-0.003886f,
	-0.188525f,-0.075703f,0.075643f,
	-0.029085f,-0.076746f,-0.273473f,
	-0.105590f,-0.238524f,-0.087465f,
	0.086122f,-0.340807f,-0.192851f,
	-0.247936f,-0.003160f,0.082106f,
	0.137988f,-0.041876f,-0.012086f,
	-0.140714f,-0.138827f,-0.064179f,
	-0.059380f,0.015642f,0.113841f,
	-0.031501f,0.007130f,-0.125767f,
	0.021294f,-0.021957f,-0.069365f,
	-0.012419f,0.019780f,-0.077459f,
	0.085524f,0.087513f,-0.107484f,
	-0.303263f,0.263672f,-0.220649f,
	-0.090267f,-0.376337f,-0.127634f,
	0.087681f,0.015985f,-0.029860f,
	0.119257f,0.140347f,0.194003f,
	0.066270f,0.127178f,-0.003765f,
	0.037563f,-0.110829f,0.000382f,
	0.034295f,-0.045737f,0.045204f,
	0.017365f,-0.072708f,0.056698f,
	0.045238f,0.187956f,-0.055878f,
	-0.132755f,0.017969f,-0.041205f,
	0.189702f,-0.020780f,-0.077422f,
	0.210419f,0.178041f,-0.005855f,
	0.104527f,-0.304323f,0.002581f,
	0.043359f,-0.060695f,-0.011878f,
	-0.000267f,0.020510f,-0.046383f,
	0.252891f,0.074246f,-0.047689f,
	-0.069874f,0.118962f,-0.052781f,
	0.086188f,0.068354f,-0.213621f,
	0.086637f,-0.171519f,0.006447f,
	0.196785f,-0.086044f,-0.068059f,
	0.100401f,0.243886f,-0.142258f,
	0.173010f,0.303375f,-0.060085f,
	-0.041181f,-0.097467f,0.073776f,
	-0.013471f,-0.133299f,-0.143570f,
	-0.302092f,-0.158342f,0.230719f,
	0.074434f,-0.143530f,0.294895f,
	-0.165626f,0.200869f,-0.130737f,
	0.102444f,0.277067f,0.078210f,
	-0.183696f,-0.010502f,-0.150481f,
	-0.070029f,-0.019635f,-0.059141f,
	-0.005930f,0.069199f,-0.013126f,
	-0.119333f,-0.007972f,0.119489f,
	0.033072f,0.081756f,-0.034481f,
	-0.108282f,-0.065310f,0.146009f,
	0.080950f,0.111320f,0.004291f,
	0.071208f,-0.112941f,0.028135f,
	-0.024632f,0.190525f,-0.285626f,
	-0.105040f,0.044008f,0.020236f,
	-0.017815f,-0.076684f,-0.065840f,
	0.083563f,0.100873f,-0.141154f,
	-0.062066f,-0.010894f,0.066110f,
	-0.056763f,0.024777f,-0.176209f,
	-0.014442f,0.052861f,0.013010f,
	-0.157546f,-0.118279f,-0.237648f,
	-0.234497f,-0.158049f,0.102635f,
	0.061685f,-0.052695f,-0.042243f,
	0.093961f,-0.025060f,0.046602f,
	0.004395f,0.150912f,0.191784f,
	0.067299f,-0.059575f,0.161018f,
	-0.233155f,-0.109721f,0.194653f,
	0.217444f,0.221231f,-0.201241f,
	-0.033689f,-0.341937f,-0.099231f,
	0.042771f,-0.028862f,0.067736f,
	0.110240f,0.274029f,-0.157689f,
	-0.055994f,0.144729f,0.090901f,
	0.211192f,0.058165f,-0.149872f,
	0.102735f,-0.044061f,-0.044795f,
	-0.042153f,-0.010955f,0.014341f,
	-0.011649f,0.099072f,-0.086419f,
	-0.018920f,0.000640f,-0.031729f,
	-0.216886f,-0.057512f,0.071195f,
	-0.188150f,0.049292f,0.258489f,
	-0.023494f,0.021489f,0.199785f,
	-0.045818f,0.066753f,-0.035593f,
	0.010986f,0.166767f,0.275085f,
	-0.177039f,0.010372f,0.167936f,
	-0.423239f,0.027466f,-0.126114f,
	-0.102035f,0.282640f,0.022622f,
	-0.023997f,0.176943f,0.093272f,
	-0.090009f,0.015338f,0.250857f,
	0.011095f,0.006703f,0.057076f,
	0.133423f,0.234639f,-0.070260f,
	-0.295994f,0.185615f,0.117148f,
	0.235480f,0.066195f,0.078641f,
	-0.026545f,0.093931f,0.008019f,
	0.181656f,-0.088719f,0.045959f,
	-0.076308f,-0.164584f,0.018271f,
	0.092026f,0.201866f,-0.106051f,
	0.019876f,0.050967f,0.176081f,
	-0.018546f,0.138749f,-0.008255f,
	-0.026049f,-0.068465f,-0.055467f,
	-0.260245f,0.221833f,-0.048541f,
	-0.169783f,0.354992f,-0.017943f,
	-0.306063f,0.074787f,0.101971f,
	0.215973f,0.107558f,-0.008808f,
	0.390235f,-0.275652f,-0.117085f,
	0.033898f,0.046047f,-0.108977f,
	-0.263507f,-0.091765f,-0.250234f,
	-0.044613f,0.149563f,0.027937f,
	-0.015397f,-0.040254f,0.065692f,
	-0.017531f,-0.013504f,0.004021f,
	0.054665f,-0.018996f,-0.006954f,
	0.033068f,0.219349f,-0.194079f,
	-0.057780f,0.011881f,0.084904f,
	0.139243f,-0.109890f,0.039145f,
	0.223272f,0.208110f,0.165882f,
	-0.008046f,0.103847f,0.278718f,
	-0.035499f,0.112662f,-0.088418f,
	-0.053118f,0.053871f,-0.054706f,
	0.118632f,0.086431f,-0.022494f,
	0.014943f,0.039622f,0.047307f,
	0.006570f,0.093461f,0.058982f,
	0.031448f,0.325716f,-0.047305f,
	-0.193710f,0.087226f,0.051790f,
	0.116154f,-0.080023f,-0.106643f,
	0.156514f,-0.222710f,0.275425f,
	-0.084294f,-0.101851f,0.425222f,
	0.030344f,-0.141370f,-0.282460f,
	0.003022f,0.108996f,-0.229152f,
	-0.133040f,0.061025f,-0.128942f,
	-0.077348f,0.013363f,-0.072511f,
	-0.050317f,0.452190f,0.094114f,
	0.053309f,-0.143722f,0.249884f,
	-0.257016f,0.100544f,0.012236f,
	-0.022056f,-0.212133f,0.023533f,
	0.153299f,0.031763f,0.034577f,
	0.161729f,0.084914f,0.050770f,
	0.320438f,0.112175f,0.135015f,
	-0.040717f,0.073400f,0.080543f,
	-0.226004f,0.143154f,0.170139f,
	0.009756f,0.068337f,0.132111f,
	0.380191f,0.233715f,0.026664f,
	-0.018016f,0.265426f,-0.110691f,
	0.041281f,0.056674f,-0.119834f,
	0.170794f,-0.112611f,0.094839f,
	0.216318f,0.002081f,0.154653f,
	-0.036815f,0.024332f,0.172587f,
	-0.064554f,0.160699f,0.101229f,
	0.114451f,0.016039f,0.293489f,
	0.023010f,-0.028932f,0.014800f,
	-0.290527f,0.172553f,0.129526f,
	-0.048159f,-0.181222f,0.305871f,
	0.065351f,-0.399962f,-0.030479f,
	0.334123f,-0.120149f,0.241310f,
	-0.203728f,-0.155627f,0.140805f,
	0.061022f,-0.016097f,0.131688f,
	0.045050f,-0.313782f,-0.279077f,
	0.034252f,-0.135512f,-0.087765f,
	0.276236f,0.036449f,0.418332f,
	-0.122146f,0.050998f,0.131453f,
	-0.087629f,0.330142f,0.061353f,
	0.228676f,0.093309f,-0.009307f,
	0.435264f,0.186185f,-0.127484f,
	0.156565f,0.013842f,-0.103874f,
	-0.274053f,-0.084119f,0.096687f,
	-0.027947f,-0.051152f,-0.078997f,
	0.013399f,0.194440f,0.072030f,
	0.000082f,0.130666f,0.052218f,
	0.064984f,-0.136859f,0.092204f,
	0.109060f,0.424779f,-0.111867f,
	0.061748f,0.160827f,-0.068538f,
	0.062960f,0.059638f,-0.181514f,
	0.018961f,0.072298f,0.003517f,
	-0.099508f,-0.225455f,-0.021791f,
	0.001955f,-0.320555f,0.159506f,
	-0.057735f,-0.054327f,-0.095525f,
	0.319748f,-0.146158f,-0.198384f,
	-0.158741f,-0.265443f,0.036635f,
	-0.093089f,-0.358379f,-0.110549f,
	-0.049805f,0.022246f,-0.036724f,
	0.223000f,0.247522f,-0.232652f,
	-0.249441f,-0.248325f,-0.071169f,
	0.000369f,0.094598f,-0.162153f,
	-0.133873f,-0.188473f,0.272734f,
	0.046594f,0.069766f,0.015561f,
	0.111582f,-0.239786f,0.034658f,
	0.093232f,0.183507f,-0.011298f,
	-0.226805f,0.514871f,-0.064144f,
	0.085949f,0.031412f,0.042790f,
	-0.043755f,-0.290797f,-0.159142f,
	0.056671f,0.167837f,0.016536f,
	-0.034538f,0.072185f,0.066973f,
	-0.021211f,0.064120f,-0.174756f,
	0.090627f,-0.055253f,0.109457f,
	0.019686f,0.004469f,-0.096316f,
	-0.038864f,-0.135083f,0.244529f,
	0.034613f,-0.069587f,0.144533f,
	-0.100009f,-0.057516f,-0.079338f,
	-0.178026f,0.085994f,0.061804f,
	-0.189256f,0.342739f,0.043372f,
	-0.046206f,0.168946f,-0.133904f,
	0.015314f,-0.090127f,-0.058530f,
	0.169657f,-0.097086f,0.013746f,
	0.185131f,-0.089445f,0.347806f,
	-0.264432f,-0.170170f,-0.335858f,
	-0.086511f,0.248252f,-0.169698f,
	0.002287f,-0.028338f,-0.266432f,
	-0.085060f,0.001974f,-0.032789f,
	0.192750f,-0.007081f,0.098197f,
	0.012577f,0.034983f,-0.003058f,
	-0.039249f,0.038498f,0.067306f,
	0.021988f,0.379705f,-0.054619f,
	-0.151707f,0.051034f,-0.016003f,
	-0.057048f,0.075729f,-0.213397f,
	-0.137847f,0.130600f,0.046198f,
	0.024786f,0.049556f,-0.045772f,
	-0.082533f,0.155397f,-0.096145f,
	0.049152f,0.270979f,-0.147022f,
	0.061153f,-0.104531f,-0.103623f,
	-0.142997f,-0.232885f,0.040538f,
	0.048806f,-0.013095f,-0.003505f,
	-0.095063f,0.241414f,-0.202255f,
	0.108558f,-0.147584f,0.162682f,
	0.217105f,0.252340f,-0.114830f,
	-0.188028f,0.417252f,-0.077456f,
	-0.112855f,0.105192f,0.073968f,
	-0.186972f,0.164022f,-0.073415f,
	-0.074349f,-0.324874f,-0.056645f,
	0.327855f,-0.271424f,-0.141142f,
	0.151049f,0.155239f,-0.083116f,
	0.035395f,-0.133176f,-0.095112f,
	0.127283f,-0.011837f,0.199750f,
	-0.120775f,0.103698f,0.063302f,
	0.014222f,0.198468f,0.137537f,
	-0.269656f,0.120644f,-0.153958f,
	-0.136743f,-0.119817f,-0.073747f,
	-0.068156f,-0.138484f,0.033507f,
	-0.106835f,0.114964f,0.023924f,
	-0.222525f,0.330321f,-0.007431f,
	-0.011739f,0.095156f,0.139086f,
	0.146766f,0.037685f,0.136122f,
	-0.086532f,-0.081295f,0.009434f,
	0.189439f,0.290592f,-0.048317f,
	0.139152f,0.224931f,0.355509f,
	0.017162f,-0.016825f,0.094198f,
	-0.237595f,0.205475f,-0.041412f,
	0.050511f,0.094900f,0.252891f,
	-0.012538f,-0.014082f,0.064629f,
	-0.059810f,0.020665f,-0.260979f,
	0.073490f,-0.242270f,0.085847f,
	0.049499f,-0.045617f,-0.015894f,
	-0.121040f,0.004350f,0.381603f,
	-0.062798f,0.055006f,0.077472f,
	-0.156846f,-0.033342f,0.035284f,
	0.105383f,0.002776f,-0.046394f,
	0.247612f,0.310528f,0.046188f,
	-0.144567f,-0.197996f,0.083309f,
	-0.317845f,-0.014793f,-0.041608f,
	-0.169858f,0.102631f,0.283962f,
	-0.168757f,0.093105f,0.050325f,
	-0.013639f,0.285100f,0.047089f,
	0.216644f,0.102018f,0.031983f,
	0.046988f,0.081482f,0.021865f,
	0.124995f,-0.193086f,0.127870f,
	0.009153f,0.178713f,-0.077949f,
	-0.235371f,-0.046817f,-0.125764f,
	-0.089381f,0.289172f,-0.129356f,
	0.312993f,0.120426f,0.296957f,
	-0.106431f,0.117096f,0.156971f,
	0.030001f,0.244577f,0.085119f,
	0.002958f,-0.035469f,-0.084615f,
	-0.052248f,-0.004298f,-0.129170f,
	-0.158458f,0.059061f,-0.041780f,
	-0.007117f,-0.174211f,0.098819f,
	-0.158387f,0.060840f,-0.064818f,
	0.117241f,-0.050754f,-0.027945f,
	-0.014301f,0.146402f,-0.118414f,
	0.186611f,-0.162182f,-0.150909f,
	-0.106992f,0.286109f,-0.055512f,
	0.109689f,-0.346409f,0.072611f,
	-0.009694f,-0.038102f,0.098565f,
	-0.034598f,0.323300f,0.020962f,
	-0.149219f,0.040596f,-0.114206f,
	0.164744f,0.048081f,0.105464f,
	0.036214f,0.099523f,0.038595f,
	0.056537f,0.036271f,0.003042f,
	-0.157110f,0.001614f,-0.133994f,
	-0.104357f,-0.032004f,0.262334f,
	0.041215f,-0.010418f,-0.037968f,
	0.223491f,-0.387946f,0.117291f,
	-0.344434f,0.110318f,-0.031448f,
	0.123562f,-0.315729f,0.164533f,
	0.008207f,0.042004f,0.050014f,
	-0.191339f,-0.069291f,-0.220065f,
	0.023845f,0.009474f,0.035598f,
	-0.173295f,-0.036604f,-0.193323f,
	-0.040347f,-0.106063f,-0.055559f,
	-0.071543f,0.136487f,0.105697f,
	-0.179027f,-0.071852f,0.117512f,
	0.064769f,-0.345895f,0.012833f,
	0.044800f,-0.032357f,-0.042161f,
	0.243586f,0.392499f,-0.180641f,
	-0.148924f,-0.181446f,0.146644f,
	-0.042773f,0.045843f,-0.176893f,
	0.025938f,0.058109f,0.242063f,
	-0.028489f,-0.024828f,0.161289f,
	0.073899f,-0.081205f,-0.023751f,
	0.026149f,0.051399f,-0.072348f,
	0.024308f,-0.041819f,-0.030578f,
	-0.077778f,0.010272f,0.066967f,
	-0.139184f,-0.018983f,0.035150f,
	-0.061359f,-0.152358f,-0.072849f,
	0.043101f,0.028278f,0.077387f,
	0.065599f,-0.049676f,0.043708f,
	-0.255767f,0.023510f,-0.076982f,
	0.020468f,-0.040630f,0.208424f,
	0.044922f,0.025184f,0.004764f,
	0.107432f,-0.009356f,0.239863f,
	-0.005475f,0.158400f,0.089743f,
	0.018352f,0.134559f,0.221650f,
	0.094423f,0.129390f,-0.031274f,
	0.048541f,0.100595f,-0.155938f,
	-0.016298f,-0.036518f,-0.149178f,
	-0.329953f,-0.327602f,-0.150086f,
	0.148403f,-0.363334f,0.028237f,
	-0.305790f,-0.009844f,-0.075571f,
	-0.045131f,0.152595f,0.228720f,
	0.039725f,-0.127469f,0.066522f,
	-0.078576f,-0.349749f,-0.146881f,
	0.013160f,-0.040312f,0.129980f,
	0.221142f,-0.106068f,0.254967f,
	0.180912f,-0.207357f,-0.196999f,
	0.098219f,0.085231f,0.121963f,
};
static const struct gllist frame={GL_V3F,GL_POINTS,500,data,NULL};
const struct gllist *s1_b=&frame;
