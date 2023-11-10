const express = require('express');
const expressHandlebars = require('express-handlebars');
const bodyParser = require('body-parser');
const session = require('express-session');
const path = require('path');

const app = express();
const PORT = process.env.PORT || 3000;

const hbs = expressHandlebars.create({
    defaultLayout: 'main',
    extname: '.hbs',
    partialsDir: [
      path.join(__dirname, 'views/partials'),
    ],
    helpers: {
      eq: (v1, v2) => v1 === v2
    }
});

// Set up handlebars
app.engine('hbs', hbs.engine);
app.set('view engine', 'hbs');

// Body parser middleware to parse request bodies
app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());

// Express session middleware
app.use(session({
  secret: 'secret',
  resave: true,
  saveUninitialized: true,
  cookie: { secure: process.env.NODE_ENV === 'production' }
}));

app.use(express.static(path.join(__dirname, 'public')));
app.set('views', path.join(__dirname, 'views'));

// Mock function to check credentials
const checkCredentials = (username, password) => {
  if (username === "teacher") {
    return { user: "teacher", userType: "teacher" };
  } else if (username === "student") {
    return { user: "student", userType: "student" };
  }
  return null;
};

// Routes
app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, 'public', 'login.html'));
});

app.post('/login', (req, res) => {
  const credentials = checkCredentials(req.body.username, req.body.password);
  if (credentials) {
    req.session.user = credentials.user;
    req.session.userType = credentials.userType;
    res.redirect('/dashboard');
  } else {
    res.redirect('/?error=Invalid credentials');
  }
});


app.get('/dashboard', (req, res) => {
  if (req.session.userType) {
    res.render('dashboard', {
      layout: 'main',
      userType: req.session.userType,
    });
  }
});

app.get('/logout', (req, res) => {
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
  res.status(500).send('Something broke!');
});


app.listen(PORT, () => {
  console.log(`Server started on port ${PORT}`);
});
