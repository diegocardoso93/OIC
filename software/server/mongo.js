const MongoClient = require('mongodb').MongoClient
const assert = require('assert')

const url = 'mongodb://localhost:27017'

const dbName = 'oic'
let oicDb
let mgClient

MongoClient.connect(url, { useNewUrlParser: true }, (err, client) => {
  assert.equal(null, err)
  console.log("Connected successfully to mongo server")

  oicDb = client.db(dbName)

  mgClient = client;

})

const mgFind = function(db, collect, select, callback) {
  const collection = db.collection(collect)
  collection.find(select).toArray(function(err, docs) {
    assert.equal(err, null)
    console.log("Found the following records")
    console.log(docs)
    callback(docs)
  })
}

const mgInsert = function(db, collect, input, callback) {
  const collection = db.collection(collect)
  collection.insertMany(input, function(err, result) {
    assert.equal(err, null)
    console.log("Inserted "+input.length+" documents into the "+collection)
    callback(result)
  })
}

const mgUpdate = function(db, collect, where, set, callback) {
  const collection = db.collection(collect)
  collection.updateOne(where
    , { $set: set }, function(err, result) {
    assert.equal(err, null)
    console.log("Updated the "+collection+" with "+where)
    callback(result)
  })  
}

const mgRemove = function(db, collect, where, callback) {
  const collection = db.collection(collect)
  collection.deleteOne(where, function(err, result) {
    assert.equal(err, null)
    console.log("Removed the "+collection+" with "+where)
    callback(result)
  })    
}

module.exports = {
  oic: oicDb,
  mgClient: mgClient,
  mgFind: mgFind,
  mgInsert: mgInsert,
  mgUpdate: mgUpdate,
  mgRemove: mgRemove
}