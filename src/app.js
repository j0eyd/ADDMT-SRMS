const express = require('express');
const expressHandlebars = require('express-handlebars');
const bodyParser = require('body-parser');
const session = require('express-session');
const path = require('path');

const app = express();
const PORT = process.env.PORT || 3000;

// Set up hbs engine
const hbs = expressHandlebars.create({
    defaultLayout: 'main',
    extname: '.hbs',
    partialsDir: [
      path.join(__dirname, 'views/partials'),
    ],
    helpers: {
      // Helper to display correct sidebar
      eq: (v1, v2) => v1 === v2
    }
});

// Set up hbs
app.engine('hbs', hbs.engine);
app.set('view engine', 'hbs');

// Body parser to parse request bodies
app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());

// Express session
app.use(session({
  secret: 'secret',
  resave: true,
  saveUninitialized: true,
  cookie: { secure: process.env.NODE_ENV === 'production' } // change to 'auto' for https encryption
}));

app.use(express.static(path.join(__dirname, 'public'))); // setup static file directory (login, register, pass reset)
app.set('views', path.join(__dirname, 'views')); // setup dynamic file directory

// Mock function to check credentials
// TODO: change this to authenticate users with database
const checkCredentials = (username, password) => {
  if (username === "teacher") {
    return { user: "teacher", userType: "teacher" };
  } else if (username === "student") {
    return { user: "student", userType: "student" };
  }
  return null;
};

// Routes
// Default: Login page
app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, 'public', 'login.html'));
});

// Login Page
app.post('/login', (req, res) => {
  const credentials = checkCredentials(req.body.username, req.body.password);
  // Make sure credentials are real
  if (credentials) {
    req.session.user = credentials.user;
    req.session.userType = credentials.userType;
    res.redirect('/dashboard');
  } else {
    res.redirect('/?error=Invalid credentials'); // redirect to login page with error
  }
});

// Dashboard Page
app.get('/dashboard', (req, res) => {
  if (req.session.userType) {
    res.render('dashboard', {
      layout: 'main',
      userType: req.session.userType,
    });
  } else {
    res.redirect('/');
  }
});

// Logout logic
app.get('/logout', (req, res) => {
  // Destroy session and redirect to login page
  req.session.destroy(err => {
    if(err) {
      console.error('Session destruction error:', err);
      res.status(500).send('Could not log out, please try again');
    } else {
      res.redirect('/');
    }
  });
});


app.use((err, req, res, next) => {
  console.error('Error during request:', req.method, req.url);
  console.error('Session:', req.session);
  console.error('Error stack:', err.stack);
  res.status(500).send('Something broke');
});


app.listen(PORT, () => {
  console.log(`Server started on port ${PORT}`);
});
