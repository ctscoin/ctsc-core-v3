// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2017 The PIVX developers
// Copyright (c) 2017-2019 The SecureCloud developers
// Copyright (c) 2019 The CTSC Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "base58.h"
#include "chainparams.h"
#include "bignum.h"
#include "random.h"
#include "util.h"
#include "utilstrencodings.h"

#include <assert.h>

#include <boost/assign/list_of.hpp>

using namespace std;
using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

/**
 * Main network
 */

//! Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress>& vSeedsOut, const SeedSpec6* data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7 * 24 * 60 * 60;
    for (unsigned int i = 0; i < count; i++) {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

//   What makes a good checkpoint block?
// + Is surrounded by blocks with reasonable timestamps
//   (no blocks before with a timestamp after, none after with
//    timestamp before)
// + Contains no strange transactions
// height, hash
// CTSC: 2018-11-02 17:43:21 UpdateTip: new best=0000022a395f7e7f9d5c0842144d85f7ec9cee0646be2afe82d9747d32fce8c6  height=350  log2_work=30.298571  tx=398  date=2018-11-02 17:43:21 progress=1.000000  cache=21
// CTSC: 2018-11-02 22:06:38 UpdateTip: new best=74cac5790bfb5a0991a1e93233436358a2eab4f0fd8564d2af32397f38687340  height=775  log2_work=42.210303  tx=1111  date=2018-11-02 22:07:23 progress=1.000234  cache=663
// CTSC: 2018-11-03 03:57:19 UpdateTip: new best=e3f27cf0eef836e8872521430a60b5a153d6639fdd09575847fee7a0d004541e  height=1250  log2_work=54.302405  tx=2061  date=2018-11-03 03:57:36 progress=1.000048  cache=21
// CTSC: 2018-11-03 16:53:13 UpdateTip: new best=d083d834a2180c4745742233d6f4e2281432bf5b84b78bc4c9009f589bb8c229  height=2025  log2_work=56.739531  tx=3615  date=2018-11-03 16:53:50 progress=1.000059  cache=39
static Checkpoints::MapCheckpoints mapCheckpoints =
    boost::assign::map_list_of
    (   0, uint256("0x00000650aaea7384d7c1576f59777f391f924195ae21fd23e5348c921315226b"))
    ( 350, uint256("0x0000022a395f7e7f9d5c0842144d85f7ec9cee0646be2afe82d9747d32fce8c6"))
    ( 775, uint256("0x74cac5790bfb5a0991a1e93233436358a2eab4f0fd8564d2af32397f38687340"))
    (1250, uint256("0xe3f27cf0eef836e8872521430a60b5a153d6639fdd09575847fee7a0d004541e"))
    (2025, uint256("0xd083d834a2180c4745742233d6f4e2281432bf5b84b78bc4c9009f589bb8c229"))
    (25000, uint256("0xf44bb4e64b3b43aa4af7fa6835065132aa7982abaf917399f75e97008e9b300f"))
    (100000, uint256("0x6e49d1f090824c8e04a09050c2fe2adf23c60d6f5face85fcff29317ffdebd88"))
    (250000, uint256("0xd30bf86791c3035ac425b38b1d8f377da53cb35636ac4f8a2e02f36a8dc4dfc2"))
    (400000, uint256("0xae797d0d710c5c73c8dd5fb47c3a420005eea382fe2999e843dab8c4a04cbc90"))
    (500000, uint256("0xa464d1b95ae54bce0fafdbbdee16ef5819d8cf1425deebd4657caaca0c4be44e"))
    (575000, uint256("0x295064f6331eb4dd765f248177546acff0ac7866d252b471dbabe36e329e5947"))
    (594375, uint256("0xd5685d5fb651918ab478a7db893a88f54645cc3d17fdc04f5f24499a9071bb39"))

    (600000, uint256("0xaded414195a8b740abdb86814d9f5a135266415de7563f7fc76aceefcfdb9203"))
    (605000, uint256("0x67d49987e8b70b424277f8f633aaf2a06637d5708de08812bcc6ac010938aa8a"))
    (612000, uint256("0xb96a25e17fee42cda6ba3bb6a22a1c6484f74aa2cec26d2ae6fc64def67e5254"))
    (618500, uint256("0xc68e80bfecd22a2c61578d711de48a31b01abb678bfc9d038db9330ed36f0dbe"))

    // TODO: Add more recent checkpoints after dev fund blocks...
    ;

static const Checkpoints::CCheckpointData data = {
    &mapCheckpoints,
    // TODO: Update the date and trx #
    1578681109,     // * UNIX timestamp of last checkpoint block (the date=)
    1274542,        // * total number of transactions between genesis and last checkpoint
                    //   (the tx=... number in the SetBestChain debug.log lines)
    1000            // * estimated number of transactions per day after checkpoint
};

static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
    boost::assign::map_list_of(0, uint256("0x001"));

static const Checkpoints::CCheckpointData dataTestnet = {
   &mapCheckpointsTestnet,
    1538412980, // 2018-10-04 22:15:13
    0,
    25};

static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
    boost::assign::map_list_of(0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataRegtest = {
    &mapCheckpointsRegtest,
    1536981815,
    0,
    0};

std::map<CScript, int> CChainParams::GetTreasuryRewardScriptAtHeight(int nHeight) const {
    std::map<CScript, int> payees;
    CBitcoinAddress vTreasuryRewardAddress(vCommunityFundWallet);
    assert(vTreasuryRewardAddress.IsValid());

    payees.emplace(GetScriptForDestination(vTreasuryRewardAddress.Get()), 150); //15%

    assert(payees.size() == 1);
    return payees;
}

class CMainParams : public CChainParams
{
public:
    CMainParams()
    {
        networkID                      = CBaseChainParams::MAIN;
        strNetworkID                   = "main";
        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */
        pchMessageStart[0]             = 0x89;
        pchMessageStart[1]             = 0xb6;
        pchMessageStart[2]             = 0xfa;
        pchMessageStart[3]             = 0xe1;
        vAlertPubKey                   = ParseHex("04ef8ffeb0991288956be66ab1dd9a1945460a006189f6f32ed1749940232afe12e2986532ca772d94958b44828f912d8caede0f8f1730dcde9f11cc057f77c8e5");
        vAlertPubKeyOld                = ParseHex("04ef8ffeb0991288956be66ab1dd9a1945460a006189f6f32ed1749940232afe12e2986532ca772d94958b44828f912d8caede0f8f1730dcde9f11cc057f77c8e5");
        nDefaultPort                   = 51527;
        nSubsidyHalvingInterval        = 1050000;
        nMaxReorganizationDepth        = 100;
        nEnforceBlockUpgradeMajority   = 750;
        nRejectBlockOutdatedMajority   = 950;
        nToCheckBlockUpgradeMajority   = 1000;
        nMinerThreads                  = 0;

        bnProofOfWorkLimit             = ~uint256(0) >> 1;
        nTargetTimespan                = 2  * 60;
        nTargetSpacing                 = 1  * 60;  // CTSC: 1 minute blocks during POW (block 1-500)

        bnProofOfStakeLimit            = ~uint256(0) >> 24;
        nTargetTimespanPOS             = 40 * 60; 
        nTargetSpacingPOS              = 1  * 60;  // CTSC: 1 minute blocks during POS

        nMaturity                      = 15; // 16 block maturity (+1 elsewhere)
        nMasternodeCountDrift          = 20;
        nMaxMoneyOut                   = 52729750 * COIN; // 85 million max supply

        /** Height or Time Based Activations **/
        nLastPOWBlock                  = 500;
        nModifierUpdateBlock           = 1; // we use the version 2 for CTSC

        nStartTreasuryBlock            = 9000001;
        nTreasuryBlockStep             = 1 * 24 * 60 * 60 / nTargetSpacingPOS; // paid once per day
        vCommunityFundWallet           = "TpE1o3R8kW54jAGBJmKBgoKYpQVdHKrFoD";


        const char* pszTimestamp       = "U.S. News & World Report 10/23/2018 America Owes the Largest Share of Global Debt";

        CMutableTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig         = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue           = 0 * COIN;
        txNew.vout[0].scriptPubKey     = CScript() << ParseHex("04bfc42ab49f2a26e297988ece66a89cb655508481f0d4f69333307418df88a80e4bfb309b7ccf8a02a2d3f1743e464c199295f04a03aa450ba82fbe4b8a4eb13e") << OP_CHECKSIG;

        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock          = 0;
        genesis.hashMerkleRoot         = genesis.BuildMerkleTree();
        genesis.nVersion               = 1;
        genesis.nTime                  = 1540339199;
        genesis.nBits                  = 0x1e0ffff0;
        genesis.nNonce                 = 21451067;

        hashGenesisBlock               = genesis.GetHash();
        assert(hashGenesisBlock        == uint256("0x00000650aaea7384d7c1576f59777f391f924195ae21fd23e5348c921315226b"));
        assert(genesis.hashMerkleRoot  == uint256("0x470973e4e1c3b449cfa22ef74518dca2acca9a2f44089e7ddec1a8b847cc87dc"));

        // CTSC: 2 seeders
        // Seeding
        vSeeds.push_back(CDNSSeedData("CTSCSeed1", "seed1.ctscoin.net"));             // seed1
        vSeeds.push_back(CDNSSeedData("CTSCSeed2", "seed2.ctscoin.net"));             // seed2
        vSeeds.push_back(CDNSSeedData("CTSCSeed3", "explorer.ctscoin.net"));          // seed3
 
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 66); // CTSC addresses start with 'T'
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 16);   // CTSC script addresses start with '3'
        base58Prefixes[SECRET_KEY]     = std::vector<unsigned char>(1, 217);  // SecCTSCreCloud private keys start with 'K'

        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x02)(0x2d)(0xa5)(0x37).convert_to_container<std::vector<unsigned char> >(); // CTSC BIP32 pubkeys start with 'tpub' (Bitcoin defaults)
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x02)(0x21)(0x34)(0x1a).convert_to_container<std::vector<unsigned char> >(); // CTSC BIP32 prvkeys start with 'tprv' (Bitcoin defaults)
        base58Prefixes[EXT_COIN_TYPE]  = boost::assign::list_of(0x80)(0x00)(0x1f)(0x55).convert_to_container<std::vector<unsigned char> >(); // CTSC BIP44 coin type is '1' - BIP44 coin type is from https://github.com/satoshilabs/slips/blob/master/slip-0044.md

        // CTSC: Not using hardcoded seeds
        //convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        fMiningRequiresPeers           = true;
        fAllowMinDifficultyBlocks      = false;
        fDefaultConsistencyChecks      = false;
        fRequireStandard               = true;
        fMineBlocksOnDemand            = false;
        fSkipProofOfWorkCheck          = false;
        fTestnetToBeDeprecatedFieldRPC = false;
        fHeadersFirstSyncingActive     = false;

        nPoolMaxTransactions           = 3;
        strSporkKey                    = "AAAAE2VjZHNhLXNoYTItbmlzdHAyNTYAAAAIbmlzdHAyNTYAAABBBLORqrN93IVkAwhGKtI5oe8SEfNbFkai5";
        strSporkKeyOld                 = "04cc17389379a0e323f53ea504d38cd71f43dc22f597805fed33a51b05ced1a3ae0db84089985f351b3737721736a82f58c8bd529f79c8ffe57e922bda792146ab";
        //nEnforceNewSporkKey            = 1535807069; // CTSC: Sporks signed after Saturday, September 1, 2018 1:04:29 PM GMT must use the new spork key
        //nRejectOldSporkKey             = 1535720669; // CTSC: Reject old spork key after Friday, August 31, 2018 1:04:29 PM GMT
        
        strMasternodePoolDummyAddress  = "TcyHQC8MusYAwGzEGaCdra7sZ3FZeChsKe";
        nStartMasternodePayments       = 4070908800; 

        nBudget_Fee_Confirmations      = 6; // Number of confirmations for the finalization fee

        nStartNewKeys                  = 1535807069; // New Spork/Alert Key: Sporks signed after Saturday, September 1, 2018 1:04:29 PM GMT must use the new spork key
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return data;
    }
};
static CMainParams mainParams;

/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams
{
public:
    CTestNetParams()
    {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";
        pchMessageStart[0] = 0x46;
        pchMessageStart[1] = 0xa6;
        pchMessageStart[2] = 0x6b;
        pchMessageStart[3] = 0xbb;
        vAlertPubKey = ParseHex("04ef8ffeb0991288956be66ab1dd9a1945460a006189f6f32ed1749940232afe12e2986532ca772d94958b44828f912d8caede0f8f1730dcde9f11cc057f77c8e5");
        nDefaultPort = 41527;
        nEnforceBlockUpgradeMajority = 51;
        nRejectBlockOutdatedMajority = 75;
        nToCheckBlockUpgradeMajority = 100;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 60; // CTSC: 1 day
        nTargetSpacing = 2 * 60;  // CTSC: 1 minute
        nLastPOWBlock = 500;
        nMaturity = 15;
        nMasternodeCountDrift = 4;
        nModifierUpdateBlock = 1;
        nMaxMoneyOut = 52729750 * COIN;

        nStartTreasuryBlock            = 10000;
        nTreasuryBlockStep             = 20; // 1 * 24 * 60 * 60 / nTargetSpacing; // paid 10 times per day
        vCommunityFundWallet           = "tcyHQC8MusYAwGzEGaCdra7sZ3FZeChsKe"; // create an accessible address on testnet

        //! Modify the testnet genesis block so the timestamp is valid for a later start.
        //genesis.nTime = 1538412980;
        //genesis.nNonce = 24429876;

        hashGenesisBlock = genesis.GetHash();
       // assert(hashGenesisBlock == uint256("0x00000689c9f1fea0e11e39e1e72edc9d46aeac860c1f15ca34cce12f4b529c04"));

        vFixedSeeds.clear();
        vSeeds.clear();

        // Testnet CTSC addresses start with 't'
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 128);
        // Testnet CTSC script addresses start with '5' or '6'
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 12);
        // Testnet private keys start with 'k'
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 108);
        // Testnet CTSC BIP32 pubkeys start with 'tpub' (Bitcoin defaults)
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x35)(0x87)(0xCF).convert_to_container<std::vector<unsigned char> >();
        // Testnet CTSC BIP32 prvkeys start with 'tprv' (Bitcoin defaults)
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x35)(0x83)(0x94).convert_to_container<std::vector<unsigned char> >();
        // Testnet CTSC BIP44 coin type is '1' (All coin's testnet default)
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x01).convert_to_container<std::vector<unsigned char> >();

        // CTSC: Not using hardcoded seeds
        //convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = false;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = true;

        nPoolMaxTransactions = 2;
        strSporkKey = "AAAAE2VjZHNhLXNoYTItbmlzdHAyNTYAAAAIbmlzdHAyNTYAAABBBLORqrN93IVkAwhGKtI5oe8SEfNbFkai5";
        strSporkKeyOld = "04abb5e65280dda6a113fadfb9877f9c399532245fe1acb61de293ab298034d5084277fab3768774a3b68cbbe5021cc5049ec8c9997a13f64da1afa0bcfb156db1";
        strMasternodePoolDummyAddress = "tcyHQC8MusYAwGzEGaCdra7sZ3FZeChsKe";
        nStartMasternodePayments = genesis.nTime + 86400; // 24 hours after genesis
        nBudget_Fee_Confirmations = 3; // Number of confirmations for the finalization fee. We have to make this very short
                                       // here because we only have a 8 block finalization window on testnet
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataTestnet;
    }
};
static CTestNetParams testNetParams;

/**
 * Regression test
 */
class CRegTestParams : public CTestNetParams
{
public:
    CRegTestParams()
    {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";
        strNetworkID = "regtest";
        pchMessageStart[0] = 0xa4;
        pchMessageStart[1] = 0xcc;
        pchMessageStart[2] = 0xa7;
        pchMessageStart[3] = 0xa9;
        nSubsidyHalvingInterval = 150;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 1;
        nTargetTimespan = 24 * 60 * 60; // CTSC: 1 day
        nTargetSpacing = 2 * 60;        // CTSC: 1 minutes
        bnProofOfWorkLimit = ~uint256(0) >> 1;
        genesis.nTime = 1536981815;
        genesis.nBits = 0x207fffff;
        genesis.nNonce = 20542302;

        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 31527;
       // assert(hashGenesisBlock == uint256("0x313ff2fd8c889cc3838f1082b2de47593ff9e527a140c7c3d0d0cce9111e1c17"));

        vFixedSeeds.clear(); //! Regtest mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Regtest mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fTestnetToBeDeprecatedFieldRPC = false;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataRegtest;
    }
};
static CRegTestParams regTestParams;

/**
 * Unit test
 */
class CUnitTestParams : public CMainParams, public CModifiableParams
{
public:
    CUnitTestParams()
    {
        networkID = CBaseChainParams::UNITTEST;
        strNetworkID = "unittest";
        nDefaultPort = 51478;
        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Unit test mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fAllowMinDifficultyBlocks = false;
        fMineBlocksOnDemand = true;
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        // UnitTest share the same checkpoints as MAIN
        return data;
    }

    //! Published setters to allow changing values in unit test cases
    virtual void setSubsidyHalvingInterval(int anSubsidyHalvingInterval) { nSubsidyHalvingInterval = anSubsidyHalvingInterval; }
    virtual void setEnforceBlockUpgradeMajority(int anEnforceBlockUpgradeMajority) { nEnforceBlockUpgradeMajority = anEnforceBlockUpgradeMajority; }
    virtual void setRejectBlockOutdatedMajority(int anRejectBlockOutdatedMajority) { nRejectBlockOutdatedMajority = anRejectBlockOutdatedMajority; }
    virtual void setToCheckBlockUpgradeMajority(int anToCheckBlockUpgradeMajority) { nToCheckBlockUpgradeMajority = anToCheckBlockUpgradeMajority; }
    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks) { fDefaultConsistencyChecks = afDefaultConsistencyChecks; }
    virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) { fAllowMinDifficultyBlocks = afAllowMinDifficultyBlocks; }
    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
};
static CUnitTestParams unitTestParams;


static CChainParams* pCurrentParams = 0;

CModifiableParams* ModifiableParams()
{
    assert(pCurrentParams);
    assert(pCurrentParams == &unitTestParams);
    return (CModifiableParams*)&unitTestParams;
}

const CChainParams& Params()
{
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams& Params(CBaseChainParams::Network network)
{
    switch (network) {
    case CBaseChainParams::MAIN:
        return mainParams;
    case CBaseChainParams::TESTNET:
        return testNetParams;
    case CBaseChainParams::REGTEST:
        return regTestParams;
    case CBaseChainParams::UNITTEST:
        return unitTestParams;
    default:
        assert(false && "Unimplemented network");
        return mainParams;
    }
}

void SelectParams(CBaseChainParams::Network network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}

bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;

    SelectParams(network);
    return true;
}
